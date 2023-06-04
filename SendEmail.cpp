#include "SendEmail.h"





User SendEmail::getUser() const
{
    return this->user;
}



std::string SendEmail::getPassword() const
{
    return this->getUser().getPassword();
}

std::string SendEmail::getSenderEmail() const
{
    return this->getUser().getSenderEmail();
}

std::string SendEmail::getReceiverEmail() const
{
    return this->getUser().getReceiverEmail();
}



std::string SendEmail::base64Encode(const std::string& input)
{
    return input;
}

//the data for the server is from external resources;
//--------------------------------------------------
void SendEmail::sendEmail()
{

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return;
    }

    SOCKET socketSmtp = socket(AF_INET, SOCK_STREAM, 0);
    if (socketSmtp == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return ;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(587); 
    serverAddress.sin_addr.s_addr = inet_addr("13.107.6.152/31"); 

    if (connect(socketSmtp, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) != 0) {
        std::cerr << "Failed to connect to the SMTP server." << std::endl;
        closesocket(socketSmtp);
        WSACleanup();
        return ;
    }

    char buffer[1024];
    std::string command;


    // Send the EHLO command
    command = "outlook.com\r\n";
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    // Start TLS encryption
    command = "STARTTLS\r\n";
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    // Perform TLS handshake
    if (WSARecv(socketSmtp, nullptr, 0, nullptr, nullptr, nullptr, nullptr) != 0) {
        std::cerr << "Failed to perform TLS handshake." << std::endl;
        closesocket(socketSmtp);
        WSACleanup();
        return ;
    }

    // Send the EHLO command again after TLS handshake
    command = "outlook.com\r\n";
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    // Send the AUTH LOGIN command
    command = "AUTH LOGIN\r\n";
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    // Send the base64-encoded username (sender's email address)
    command = base64Encode(getSenderEmail())+"\r\n"; 
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    // Send the base64-encoded password
    command = getPassword() + "\r\n";
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    // Send the MAIL FROM command
    command = getSenderEmail() + "\r\n"; 
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    // Send the RCPT TO command
    command = getReceiverEmail() + "\r\n"; 
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;


    std::ifstream file("WeatherReport.csv"); 
    if (!file.is_open())
    {
        std::cerr << "The report file can not be open/found." << std::endl;
        return;
    }
    std::string fileContent = "\r\n";
    send(socketSmtp, fileContent.c_str(), fileContent.length(), 0);
    char fileBuffer[1024];
    int bytesRead;
    while ((bytesRead = file.read(fileBuffer, sizeof(fileBuffer)).gcount()) > 0) {
         send(socketSmtp, fileBuffer, bytesRead, 0);
    }

     file.close();
    

    // Send the QUIT command
    command = "QUIT\r\n";
    send(socketSmtp, command.c_str(), command.length(), 0);
    recv(socketSmtp, buffer, sizeof(buffer), 0);
    std::cout << buffer;

    closesocket(socketSmtp);
    WSACleanup();

    std::cout << "Email sent successfully." << std::endl;

}





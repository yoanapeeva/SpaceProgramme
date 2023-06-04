#include "User.h"



void User::setPassword(std::string password)
{
	this->password = password;
}

void User::setSenderEmail(std::string senderEmail)
{
	this->senderEmail = senderEmail;
}

void User::setReceiverEmail(std::string receiverEmail)
{
	this->receiverEmail = receiverEmail;
}



std::string User::getPassword() const
{
	return this->password;
}

std::string User::getSenderEmail() const
{
	return this->senderEmail;
}

std::string User::getReceiverEmail() const
{
	return this->receiverEmail;
}


void User::enterPassword()
{
	std::string password;
	std::cout << "Please enter your password : " << std::endl;

	char ch;
	while ((ch = _getch()) != '\r')
	{
		std::cout << "*";
		password += ch;
	}
	std::cout << std::endl;
	setPassword(password);
}

void User::enterEmails()
{
	std::string senderEmail;
	std::string receiverEmail;
	std::cout << "Please enter your email : " << std::endl;
	std::cin >> senderEmail;
	std::cout << "Please enter recipient email address : " << std::endl;
	std::cin >> receiverEmail;
	setSenderEmail(senderEmail);
	setReceiverEmail(receiverEmail);
}

void User::setDataUser()
{
	enterEmails();
	enterPassword();
}

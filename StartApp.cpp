#include "StartApp.h"

SendEmail StartApp::getEmailInformation() const
{
    return this->emailInformation;
}

Commands StartApp::getData() const
{
    return this->data;
}

void StartApp::greating()
{

    std::cout << "Welcome on board!" << std::endl;
    std::cout << "Our mission is to provide accurate weather information for our upcoming trip in July." << std::endl;
}

void StartApp::enterDataOfUser()
{
    getEmailInformation().getUser().setDataUser();
}

void StartApp::enterData()
{
      getData().enterAllInformation();
}

void StartApp::sendEmail()
{
    getEmailInformation().sendEmail();
}

void StartApp::startApplication()
{
    greating();
    enterDataOfUser();
    enterData();
    sendEmail();
    
    
}



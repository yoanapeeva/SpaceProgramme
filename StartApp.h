#pragma once
#include"SendEmail.h"

//class for entering the user`s information and sending the email with weather report
class StartApp
{
private:
	Commands data;
	SendEmail emailInformation;
public:
	SendEmail getEmailInformation()const;
	Commands getData()const;

	//a greating sentence for starting the application
	void greating();

	//functions to enter the data from the standard input
	void enterDataOfUser();
	void enterData();

	//functions to send email 
	void sendEmail();

	//start the application
	void startApplication();

};
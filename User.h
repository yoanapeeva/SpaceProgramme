#pragma once
#include<iostream>
#include <conio.h>
//class for user information
class User
{
private:

	std::string password;
	std::string senderEmail;
	std::string receiverEmail;
public:
	//setters
	void setPassword(std::string password);
	void setSenderEmail(std::string senderEmail);
	void setReceiverEmail(std::string receiverEmail);

	//getters
	std::string getPassword() const;
	std::string getSenderEmail() const;
	std::string getReceiverEmail() const;

	//functions to entering the user`s data 
	void enterPassword();
	void enterEmails();
	void setDataUser();

};
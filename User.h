#pragma once
#include<iostream>
class User
{
private:
	std::string fileName;
	std::string password;
	std::string senderEmail;
	std::string receiverEmail;
public:
	void setFileName(std::string fileName);

	void setPassword(std::string password);

	void setSenderEmail(std::string senderEmail);

	void setReceiverEmail(std::string receiverEmail);

	std::string getFileName() const;

};
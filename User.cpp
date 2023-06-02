#include "User.h"

void User::setFileName(std::string fileName)
{
	int length = fileName.size();
	if (fileName.substr(length - 4, length ) == ".csv")
	{
		this->fileName = fileName;
	}
	else
	{
		throw std::invalid_argument("The file format is incorrect");
	}
}

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

std::string User::getFileName() const
{
	return this->fileName;
}

#include "User.h"

void User::setFileName(std::string fileName)
{
	int length = fileName.size();
	if (fileName.size()>4&&fileName.substr(length - 4, length ) == ".csv")
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

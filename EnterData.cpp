#include "EnterData.h"

Commands EnterData::getCommands() const
{
	return this->command;
}

void EnterData::setNameFile()
{
	this->command.enterNameOfFile();
}

void EnterData::setEmails()
{
	this->command.enterEmails();
}

void EnterData::setPassword()
{
	this->command.enterPassword();
}

void EnterData::setDataUser()
{
	setNameFile();
	setEmails();
	setPassword();
}

void EnterData::openFile()
{
	this->command.openFile();
}

void EnterData::createDataFile()
{
	this->command.createDataFile();
}



void EnterData::enterAllInformation()
{
	setDataUser();
	openFile();
	createDataFile();

}

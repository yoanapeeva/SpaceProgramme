#pragma once
#include"Commands.h"

class EnterData
{
private :
	Commands command;
public:

	Commands getCommands()const;
	void setNameFile();
	void setEmails();
	void setPassword();
	void setDataUser();
	void openFile();
	void createDataFile();
	void enterAllInformation();
};
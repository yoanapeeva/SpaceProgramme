#pragma once
#include <winsock2.h>

#include"EnterData.h"
#pragma warning (disable:4996)
#pragma comment(lib, "ws2_32.lib")
class SendEmail
{
private :
	EnterData data;
public:
	void greating();
	EnterData getData()const;
	void enterData();
	void sendEmail();
	void startApplication();
	std::string base64Encode(const std::string& input);
	Commands getCommands()const;
	std::string getFileName()const;
	std::string getPassword()const;
	std::string getSenderEmail()const;
	std::string getReceiverEmail()const;

};

#pragma once
#include <winsock2.h>

#include"Commands.h"
#pragma warning (disable:4996)
#pragma comment(lib, "ws2_32.lib")

//class to send email with the collected information
class SendEmail
{
private :

	User user;
public:
		
	//getters

	User getUser()const;

	std::string getPassword()const;
	std::string getSenderEmail()const;
	std::string getReceiverEmail()const;

	std::string base64Encode(const std::string& input); 
	void sendEmail();
	

	



};

#pragma once
#include<iostream>

//class with static functions for verification of words
class HelperFunction
{
public:
	static bool isYes(std::string y);
	static bool isNo(std::string n);
	static bool isSameWords(std::string first, std::string second);


};
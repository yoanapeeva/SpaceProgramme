#pragma once
#include<iostream>
#include "Cloud.h"
#include "HelperFunction.h"

//class for creating a structure with the parameters from the file as private data members
class DayParameters
{
private:
	int day;
	int temperature;
	int wind;
	int humidity;
	int precipitation;
	bool lightning;
	CloudType type;

public:
	DayParameters();


	//getters
	int getDay()const;
	int getTemperature()const;
	int getWind()const;
	int getHumidity() const;
	int getPrecipitation()const;
	bool getLightning() const;
	CloudType getCloudType()const;

	//setters
	void setDay(int day);
	void setTemperature(int temperature);
	void setWind(int wind);
	void setHumidity(int humidity);
	void setPrecipitation(int precipitation);
	void setLightning(std::string lightning);
	void setCloudsType(std::string type);

	//function to check if a day has acceptable parameters for launching 
	bool isAcceptable();

	std::string convertLightningToString();
	std::string convertCloudTypeToToString();

	//functions for entering the data from a stream / from the console
	friend void enterDate(std::istream& is, DayParameters& day);
	friend void enterTemperaturre(std::istream& is, DayParameters& day);
	friend void enterWind(std::istream& is, DayParameters& day);
	friend void enterHumidity(std::istream& is, DayParameters& day);
	friend void enterPrecipitation(std::istream& is, DayParameters& day);
	friend void enterLightning(std::istream& is, DayParameters& day);
	friend void enterCloudType(std::istream& is, DayParameters& day);
	friend std::istream& operator>>(std::istream& is, DayParameters& day);

};
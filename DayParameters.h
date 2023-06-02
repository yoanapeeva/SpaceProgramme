#pragma once
#include<iostream>
#include "Cloud.h"
#include "HelperFunction.h"

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

	void setDay(int day);
	void setTemperature(int temperature);
	void setWind(int wind);
	void setHumidity(int humidity);
	void setPrecipitation(int precipitation);
	void setLightning(std::string lightning);
	void setCloudsType(std::string type);

	int getDay()const;
	int getTemperature()const;
	int getWind()const;
	int getHumidity() const;
	int getPrecipitation()const;
	bool getLightning() const;
	CloudType getCloudType()const;

	bool isAcceptable();
	std::string convertLightningToString();
	std::string convertCloudTypeToToString();

	friend void enterDate(std::istream& is, DayParameters& day);
	friend void enterTemperaturre(std::istream& is, DayParameters& day);
	friend void enterWind(std::istream& is, DayParameters& day);
	friend void enterHumidity(std::istream& is, DayParameters& day);
	friend void enterPrecipitation(std::istream& is, DayParameters& day);
	friend void enterLightning(std::istream& is, DayParameters& day);
	friend void enterCloudType(std::istream& is, DayParameters& day);
	friend std::istream& operator>>(std::istream& is, DayParameters& day);

};
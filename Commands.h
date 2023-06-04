#pragma once
#include<iostream>
#include<fstream>
#include <functional>
#include<vector>
#include <string>
#include<set>
#include<algorithm>
#include "DayParameters.h"
#include "User.h"

//class to read (write) from (in) a file
class Commands
{
private:
	
	std::string fileName;
	std::vector<DayParameters> days;

	//checks if the information for a date has been already filled
	std::set<int> datesOfJuly;

	//check if there are any errors in the information table or during the opening of the user's file.
	bool error;

public:
	Commands():error(false) {};

	//getters 
	std::string getFileName()const;
	std::vector<DayParameters> getDays() const;
	std::set<int> getDatesOfJuly()const;
	bool getError()const;

	

	//setters
	void setFileName(std::string fileName);
	void setError(bool error);

	void setDays(int index,int day);
	void setTemperature(int index, int temperature);
	void setWindSpeed(int index, int wind);
	void setHumidity(int index, int humidity);
	void setPrecipitation(int index, int precipitation);
	void setLightning(int index, std::string lightning);
	void setCloudType(int index, std::string type);


	void insertDay(DayParameters& day);
	void insertDatesOfJuly(int day);
	

	void clearDatesOfJuly();	
	void clearDays();
	void resaizeDays(int size);

	//functions to entering the user`s data 
	void enterNameOfFile();
	

	//function to read from a file
	void openFile();

	//funtion to fill the DayPrameter structure with the data from the file
	void readTextFromFile(std::ifstream& file, std::string line, std::vector<std::vector<std::string>>& table);
	void readTableFromFile(std::vector<std::vector<std::string>>& table, std::string& line, int& startPosition, int& endPosition, int i, std::ifstream& file);
	void readIndexDayRow(std::vector<std::vector<std::string>>& table);
	void readTemperatureRow(std::vector<std::vector<std::string>>& table);
	void readWindSpeedRow(std::vector<std::vector<std::string>>& table);
	void readHumidityRow(std::vector<std::vector<std::string>>& table);
	void readPrecipitationRow(std::vector<std::vector<std::string>>& table);
	void readLightningRow(std::vector<std::vector<std::string>>& table);
	void readCloudRow(std::vector<std::vector<std::string>>& table);
	void readAllTableRows(std::vector<std::vector<std::string>>& table);
	void readAllInformationFromFile(std::ifstream& file);

	//functions that provide the opportunity for manually entering weather data.
	void additionalData();
	int enterNumberOfAdditionalDates();
	void enterAdditionalDates(int numberOfDays);

	//helpful function for repeating a question
	void addDataManuallyQuestion();
	void enterFileNameAgainQuestion(bool& tmp);
	void enterTheInformationForDateAgainQuestion(bool& tmp,int&);


	//functions to calculate the average/max/min/median values
	double averageTemperature();
	double averageWind();
	double averageHumidity();
	double averagePrecipitation();
	void fillAverageColumn(std::vector<std::vector<std::string>>& table);

	int maxTemperature();
	int maxWind();
	int maxHumidity();
	int maxPrecipitation();
	void fillMaxColumn(std::vector<std::vector<std::string>>& table);

	int minTemperature();
	int minWind();
	int minHumidity();
	int minPrecipitation();
	void fillMinColumn(std::vector<std::vector<std::string>>& table);

	double medianTemperature();
	double medianWind();
	double medianHumidity();
	double medianPrecipitation();
	void fillMedianColumn(std::vector<std::vector<std::string>>& table);
	

	//functions to filter the most suitable day for launch
	std::vector<DayParameters> filterAcceptableDays();
	DayParameters filterMostAppropriateDay(std::vector<DayParameters>& dates);
	
	//function to fill the table for the weather report
	void fillParametersColumn(std::vector<std::vector<std::string>>& table);
	void fillLaunchDayColumn(std::vector<std::vector<std::string>>& table, DayParameters& day);
	void fillEmptyColumn(std::vector<std::vector<std::string>>& table);
	void fillEmptyTable(std::vector<std::vector<std::string>>& table);
	std::vector<std::vector<std::string>> fillParametersTable();
	std::vector<std::vector<std::string>> fillTable();

	//functions for creating and writing in the weather report file 
	void createDataFile();
	void writeTableInFile(std::vector<std::vector<std::string>>& table,std::ofstream& file);

	void enterAllInformation();



};
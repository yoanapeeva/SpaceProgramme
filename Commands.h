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

class Commands
{
private:
	User user;
	std::vector<DayParameters> days;
	std::set<int> datesOfJuly;
	bool error;
public:
	Commands():error(false) {};

	User getUser()const;
	std::vector<DayParameters> getDays() const;
	std::set<int> getDatesOfJuly()const;
	bool getError()const;

	void setError(bool error);

	void setDays(int index,int day);
	void setTemperature(int index, int temperature);
	void setWindSpeed(int index, int wind);
	void setHumidity(int index, int humidity);
	void setPrecipitation(int index, int precipitation);
	void setLightning(int index, std::string lightning);
	void setCloudType(int index, std::string type);


	void userSetFileName(std::string fileName);
	void userSetRassword(std::string password);
	void userSetSenderEmail(std::string senderEmail);
	void userSetReceiverEmail(std::string receiverEmail);
	void insertDay(DayParameters& day);
	void insertDatesOfJuly(int day);
	

	void clearDatesOfJuly();	
	void resaizeDays(int size);

	void openFile();
	void readAllInformationFromFile(std::ifstream& file);
	void enterNameOfFile();
	void enterPassword();
	void enterEmails();
	void additionalData();
	int enterNumberOfAdditionalDates();
	void enterAdditionalDates(int numberOfDays);


	void addDataManuallyQuestion();
	void enterFileNameAgainQuestion(bool& tmp);
	void enterTheInformationForDateAgainQuestion(bool& tmp,int&);

	void readTextFromFile(std::ifstream& file,std::string line, std::vector<std::vector<std::string>>& table);
	void readTableFromFile(std::vector<std::vector<std::string>>& table,std::string& line, int& startPosition, int& endPosition,int i, std::ifstream& file);
	void readIndexDayRow(std::vector<std::vector<std::string>>& table);
	void readTemperatureRow(std::vector<std::vector<std::string>>& table);
	void readWindSpeedRow(std::vector<std::vector<std::string>>& table);
	void readHumidityRow(std::vector<std::vector<std::string>>& table);
	void readPrecipitationRow(std::vector<std::vector<std::string>>& table);
	void readLightningRow(std::vector<std::vector<std::string>>& table);
	void readCloudRow(std::vector<std::vector<std::string>>& table);
	void readAllTableRows(std::vector<std::vector<std::string>>& table);

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

	void fillParametersColumn(std::vector<std::vector<std::string>>& table);
	void fillLaunchDayColumn(std::vector<std::vector<std::string>>& table,  DayParameters& day);
	void fillEmptyColumn(std::vector<std::vector<std::string>>& table);
	void fillEmptyTable(std::vector<std::vector<std::string>>& table);


	std::vector<DayParameters> filterAcceptableDays();
	DayParameters filterMostAppropriateDay(std::vector<DayParameters>& dates);
	std::vector<std::vector<std::string>> fillTable();
	std::vector<std::vector<std::string>> fillParametersTable();

	void createNewFile();
	void writeTableInFile(std::vector<std::vector<std::string>>& table,std::ofstream& file);



};
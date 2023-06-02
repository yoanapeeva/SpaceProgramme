#include "Commands.h"
#include <conio.h>


User Commands::getUser() const
{
	return this->user;
}

std::vector<DayParameters> Commands::getDays() const
{
	return this->days;
}

std::set<int> Commands::getDatesOfJuly() const
{
	return this->datesOfJuly;
}

bool Commands::getError() const
{
	return this->error;
}

std::string Commands::getFileName() const
{
	return this->getUser().getFileName();
}

std::string Commands::getPassword() const
{
	return this->getUser().getPassword();
}

std::string Commands::getSenderEmail() const
{
	return this->getUser().getSenderEmail();
}
std::string Commands::getReceiverEmail() const
{
	return this->getUser().getReceiverEmail();
}
void Commands::setError(bool error)
{
	this->error = error;
}

void Commands::setDays(int index,int day)
{
	this->days[index].setDay(day);
}

void Commands::setTemperature(int index, int temperature)
{
	this->days[index].setTemperature(temperature);
}

void Commands::setWindSpeed(int index, int wind)
{
	this->days[index].setWind(wind);
}

void Commands::setHumidity(int index, int humidity)
{
	this->days[index].setHumidity(humidity);
}

void Commands::setPrecipitation(int index, int precipitation)
{
	this->days[index].setPrecipitation(precipitation);
}

void Commands::setLightning(int index,std::string lightning)
{
	this->days[index].setLightning(lightning);
}

void Commands::setCloudType(int index, std::string type)
{
	this->days[index].setCloudsType(type);
}

void Commands::userSetFileName(std::string fileName)
{
	this->user.setFileName(fileName);
}

void Commands::userSetRassword(std::string password)
{
	this->user.setPassword(password);
}

void Commands::userSetSenderEmail(std::string senderEmail)
{
	this->user.setSenderEmail(senderEmail);
}

void Commands::userSetReceiverEmail(std::string receiverEmail)
{
	this->user.setReceiverEmail(receiverEmail);
}

void Commands::insertDay(DayParameters& day)
{
	this->days.push_back(day);
}

void Commands::insertDatesOfJuly(int day)
{
	datesOfJuly.insert(day);
}

void Commands::clearDatesOfJuly()
{
	this->datesOfJuly.clear();
}

void Commands::resaizeDays(int size)
{
	this->days.resize(size);
}

void Commands::openFile()
{
	std::ifstream file(getUser().getFileName());

	if (!file.is_open())
	{
		std::cerr << "The file couldn`t be open/couldn`t be found." << std::endl;
		addDataManuallyQuestion();
		setError(true);
		return;
	}	
	
	try
	{
		readAllInformationFromFile(file);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		addDataManuallyQuestion();
		file.close();
		return;
	}
	file.close();
	
	if (getError())
	{
		clearDatesOfJuly();
		std::cerr << "The file could not be processed." << std::endl;
	}

	addDataManuallyQuestion();
	
	
}

void Commands::readAllInformationFromFile(std::ifstream& file)
{
	std::string line;
	std::vector<std::vector<std::string>> table;
	readTextFromFile(file, line, table);
	if (getError())
	{
		throw std::invalid_argument("The file could not be processed.");
	}

	resaizeDays(table[0].size() - 1);

	readAllTableRows(table);
}

void Commands::enterNameOfFile()
{
	std::string fileName;
	std::cout << "Please enter the name of the file : " << std::endl;
	bool tmp = true;
	while (tmp)
	{
		try
		{
			std::cin >> fileName;
			userSetFileName(fileName);
			tmp = false;
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
			enterFileNameAgainQuestion(tmp);
		
		}
	}
}

void Commands::enterPassword()
{
	std::string password;
	std::cout << "Please enter your password : " << std::endl;
	
	char ch;
	while ((ch = _getch()) != '\r')
	{
		std::cout << "*";
		password += ch;
	}
	std::cout<<std::endl;
	userSetRassword(password);
}

void Commands::enterEmails()
{
	std::string senderEmail;
	std::string receiverEmail;
	std::cout << "Please enter your email : " << std::endl;
	std::cin >> senderEmail;
	std::cout << "Please enter an email address to connect with : " << std::endl;
	std::cin >> receiverEmail;
	userSetSenderEmail(senderEmail);
	userSetReceiverEmail(receiverEmail);

}
void Commands::readTextFromFile(std::ifstream& file, std::string line, std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < 7; i++)
	{
		std::getline(file, line);
		int startPosition = 0;
		int endPosition = line.find(',');
		table.push_back({});

		while (endPosition != std::string::npos && !getError())
		{
			readTableFromFile(table, line, startPosition, endPosition, i, file);

		}
		if (!getError())
		{
			readTableFromFile(table, line, startPosition, endPosition, i, file);
		}
	}
}

void Commands::readTableFromFile(std::vector<std::vector<std::string>>& table, std::string& line, int& startPosition, int& endPosition,int i,std::ifstream& file)
{
	std::string word;
	word = line.substr(startPosition, endPosition - startPosition);
	if (word == "")
	{
		file.close();
		std::cerr << "There is blank cell in the table in the row of " << table[i][0] << ". " << std::endl;
		setError(true);

	}
	table[i].push_back(word);
	startPosition = endPosition + 1;
	endPosition = line.find(',', startPosition);

}

void Commands::additionalData()
{
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << "Please enter the number of days which will be added to the table : " << std::endl;
	int numberOfDays;
	numberOfDays= enterNumberOfAdditionalDates();
	enterAdditionalDates(numberOfDays);
}

int Commands::enterNumberOfAdditionalDates()
{
	int numberOfDays=0;
	std::cin >> numberOfDays;
	bool tmp = true;
	while (tmp)
	{
		if (numberOfDays <= 0 || numberOfDays > 32||numberOfDays>(31-getDatesOfJuly().size()))
		{
			std::cout << "Invalid number." << std::endl;
			std::cout << "Please enter a number again : " << std::endl;
			int number;
			std::cin >> number;
			numberOfDays = number;
			return numberOfDays;
		}
		else
		{
			tmp = false;
		}
	}
	return numberOfDays;
}

void Commands::enterAdditionalDates(int numberOfDays)
{

	for (int i = 0; i < numberOfDays; i++)
	{
		bool tmp = true;
		while (tmp)
		{
			DayParameters day;
			std::cin >> day;

			if (getDatesOfJuly().count(day.getDay()) == 0)
			{
				insertDay(day);
				insertDatesOfJuly(day.getDay());
				std::cout << "--------------------------------------------------------------------" << std::endl;
				tmp = false;
			}
			else
			{

				enterTheInformationForDateAgainQuestion(tmp, i);
			}
		}
	}
}




void Commands::addDataManuallyQuestion()
{
	std::cout << "Do you want to add data manually? (y/n) " << std::endl;
	bool tmp = true;;
	while (tmp)
	{
		std::string answer;
		std::cin >> answer;
		if (HelperFunction::isNo(answer))
		{
			tmp = false;

		}
		else if (HelperFunction::isYes(answer))
		{
			additionalData();
			tmp = false;

		}
		else
		{
			std::cout << "Please enter your answer again : " << std::endl;
		}
	}
}

void Commands::enterFileNameAgainQuestion(bool& tmp)
{
	std::cout << "Do you want to continue (y/n) " << std::endl;

	bool tmp2 = true;
	while (tmp2)
	{
		std::string answer;
		std::cin >> answer;
		if (HelperFunction::isNo(answer))
		{
			tmp = false;
			tmp2 = false;
		}
		else if (HelperFunction::isYes(answer))
		{
			std::cout << "Please enter the name of the file again : " << std::endl;
			tmp2 = false;
		}
		else
		{
			std::cout << "Please enter your answer again : " << std::endl;
		}
	}
}

void Commands::enterTheInformationForDateAgainQuestion(bool& tmp,int& i)
{
	std::cout << "The information for this date of July has already been filled. " << std::endl;
	std::cout << "Do you want to repeat the information (y/n) ?" << std::endl;

	bool tmp2 = true;
	while (tmp2)
	{
		std::string answer;
		std::cin >> answer;
		if (HelperFunction::isNo(answer))
		{
			tmp = false;
			tmp2 = false;
			std::cout << "--------------------------------------------------------------------" << std::endl;
		}
		else if (HelperFunction::isYes(answer))
		{
			tmp2 = false;
			tmp = false;
			i--;
			std::cout << "--------------------------------------------------------------------" << std::endl;
		}
		else
		{
			std::cout << "Please enter your answer again : " << std::endl;
		}
	}
}


void Commands::readIndexDayRow(std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < table[0].size() - 1; i++)
	{
		try
		{
			setDays(i,std::stoi(table[0][i + 1]));
			insertDatesOfJuly(std::stoi(table[0][i + 1]));
		}
		catch (std::out_of_range& e)
		{
			std::cerr << "There is an invalid date in the table. " << std::endl;
			setError(true);
			return;
		}
	}
}

void Commands::readTemperatureRow(std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < table[1].size() - 1; i++)
	{
		setTemperature(i,std::stoi(table[1][i + 1]));
	}
}

void Commands::readWindSpeedRow(std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < table[2].size() - 1; i++)
	{
		try
		{
			setWindSpeed(i,std::stoi(table[2][i + 1]));
		}
		catch (std::out_of_range& e)
		{ 
			std::cerr << "There is an invalid wind speed in the table. " << std::endl;
			setError(true);
			return;
		}
	}
}

void Commands::readHumidityRow(std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < table[3].size() - 1; i++)
	{
		try
		{
			setHumidity(i,std::stoi(table[3][i + 1]));
		}
		catch (std::out_of_range& e)
		{
			std::cerr << "There is an invalid humidity percentage in the table. " << std::endl;
			setError(true);
			return;
		}
	}
}

void Commands::readPrecipitationRow(std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < table[4].size() - 1; i++)
	{
		try
		{
			setPrecipitation(i,std::stoi(table[4][i + 1]));
		}
		catch (std::out_of_range& e)
		{
			std::cerr << "There is an invalid precipitation percentage in the table. " << std::endl;
			setError(true);
			return;
		}
	}
}

void Commands::readLightningRow(std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < table[5].size() - 1; i++)
	{
		try
		{
			setLightning(i,table[5][i + 1]);
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << "There is an invalid information for lightninng storms in the table. " << std::endl;
			setError(true);
			return;
		}
	}
	
}

void Commands::readCloudRow(std::vector<std::vector<std::string>>& table)
{
	for (int i = 0; i < table[6].size() - 1; i++)
	{
		try
		{
			setCloudType(i,table[6][i + 1]);
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << "There is an invalid cloud type in the table. " << std::endl;
			setError(true);
			return;
		}
	}
}

void Commands::readAllTableRows(std::vector<std::vector<std::string>>& table)
{
	readIndexDayRow(table);

	readTemperatureRow(table);

	readWindSpeedRow(table);

	readHumidityRow(table);

	readPrecipitationRow(table);

	readLightningRow(table);

	readCloudRow(table);
}



double Commands::averageTemperature()
{
	double average = 0;
	for (int i = 0; i < getDays().size(); i++)
	{
		average +=(double) getDays()[i].getTemperature();
	}
	return (average / getDays().size());
}

double Commands::averageWind()
{
	double average = 0;
	for (int i = 0; i < getDays().size(); i++)
	{
		average += (double)getDays()[i].getWind();
	}
	return (average / getDays().size());
}

double Commands::averageHumidity()
{
	double average = 0;
	for (int i = 0; i < getDays().size(); i++)
	{
		average += (double)getDays()[i].getHumidity();
	}
	return (average / getDays().size());
}

double Commands::averagePrecipitation()
{
	double average = 0;
	for (int i = 0; i < getDays().size(); i++)
	{
		average += (double)getDays()[i].getPrecipitation();
	}
	return (average / getDays().size());
}

void Commands::fillAverageColumn(std::vector<std::vector<std::string>>& table)
{
	table[1].push_back(std::to_string(averageTemperature()));
	table[2].push_back(std::to_string(averageWind()));
	table[3].push_back(std::to_string(averageHumidity()));
	table[4].push_back(std::to_string(averagePrecipitation()));
	table[5].push_back("");
	table[6].push_back("");
}

int Commands::maxTemperature()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::max_element(dates.begin(), dates.end(), [](const DayParameters& first,const  DayParameters& second)
		{return first.getTemperature() < second.getTemperature(); })).getTemperature();
	
}

int Commands::maxWind()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::max_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second)
		{return first.getWind() < second.getWind(); })).getWind();
}

int Commands::maxHumidity()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::max_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second)
		{return first.getHumidity() < second.getHumidity(); })).getHumidity();
}

int Commands::maxPrecipitation()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::max_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second)
		{return first.getPrecipitation() < second.getPrecipitation(); })).getPrecipitation();
}

void Commands::fillMaxColumn(std::vector<std::vector<std::string>>& table)
{
	table[1].push_back(std::to_string(maxTemperature()));
	table[2].push_back(std::to_string(maxWind()));
	table[3].push_back(std::to_string(maxHumidity()));
	table[4].push_back(std::to_string(maxPrecipitation()));
	table[5].push_back("");
	table[6].push_back("");
}


int Commands::minTemperature()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::min_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second)
		{return first.getTemperature() < second.getTemperature(); })).getTemperature();
}

int Commands::minWind()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::min_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second)
		{return first.getWind() < second.getWind(); })).getWind();
}

int Commands::minHumidity()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::min_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second)
		{return first.getHumidity() < second.getHumidity(); })).getHumidity();
}

int Commands::minPrecipitation()
{
	std::vector<DayParameters> dates = getDays();
	return (*std::min_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second)
		{return first.getPrecipitation() < second.getPrecipitation(); })).getPrecipitation();
}

void Commands::fillMinColumn(std::vector<std::vector<std::string>>& table)
{
	table[1].push_back(std::to_string(minTemperature()));
	table[2].push_back(std::to_string(minWind()));
	table[3].push_back(std::to_string(minHumidity()));
	table[4].push_back(std::to_string(minPrecipitation()));
	table[5].push_back("");
	table[6].push_back("");
}


double Commands::medianTemperature()
{
	int size = getDays().size();
	if (size % 2 == 0)
	{
		return (double)(getDays()[size / 2 - 1].getTemperature() + getDays()[size / 2].getTemperature()) / 2;
	}
	return (double)getDays()[size/2].getTemperature();
}

double Commands::medianWind()
{
	int size = getDays().size();
	if (size % 2 == 0)
	{
		return(double) (getDays()[size / 2 - 1].getWind() + getDays()[size / 2].getWind()) / 2;
	}
	return (double)getDays()[size/2].getWind();
}

double Commands::medianHumidity()
{
	int size = getDays().size();
	if (size % 2 == 0)
	{
		return (double)(getDays()[size / 2 - 1].getHumidity() + getDays()[size / 2].getHumidity()) / 2;
	}
	return (double)getDays()[size/2].getHumidity();
}

double Commands::medianPrecipitation()
{
	int size = getDays().size();
	if (size % 2 == 0)
	{
		return (double)(getDays()[size / 2 - 1].getPrecipitation() + getDays()[size / 2].getPrecipitation()) / 2;
	}
	return (double)getDays()[size/2].getPrecipitation();
}

void Commands::fillMedianColumn(std::vector<std::vector<std::string>>& table)
{
	table[1].push_back(std::to_string(medianTemperature()));
	table[2].push_back(std::to_string(medianWind()));
	table[3].push_back(std::to_string(medianHumidity()));
	table[4].push_back(std::to_string(medianPrecipitation()));
	table[5].push_back("");
	table[6].push_back("");
}

void Commands::fillParametersColumn(std::vector<std::vector<std::string>>& table)
{
	fillAverageColumn(table);
	fillMaxColumn(table);
	fillMinColumn(table);
	fillMedianColumn(table);
}

void Commands::fillLaunchDayColumn(std::vector<std::vector<std::string>>& table, DayParameters& day)
{
	table[0][5] += " - "+ std::to_string(day.getDay()) + " July";
	table[1].push_back(std::to_string(day.getTemperature()));
	table[2].push_back(std::to_string(day.getWind()));
	table[3].push_back(std::to_string(day.getHumidity()));
	table[4].push_back(std::to_string(day.getPrecipitation()));
	table[5].push_back(day.convertLightningToString());
	table[6].push_back(day.convertCloudTypeToToString());
}

void Commands::fillEmptyColumn(std::vector<std::vector<std::string>>& table)
{

	for (int i = 1; i < 7; i++)
	{
		table[i].push_back({ "N/A" });
	}
}

void Commands::fillEmptyTable(std::vector<std::vector<std::string>>& table)
{
	for (int i = 1; i < 6; i++)
	{
		fillEmptyColumn(table);
	}
}

std::vector<DayParameters> Commands::filterAcceptableDays()
{
	std::vector<DayParameters> filtred;
	for (int i = 0; i < getDays().size(); i++)
	{
		if (getDays()[i].isAcceptable())
		{
			filtred.push_back(getDays()[i]);
		}
	}
	return filtred;
}

DayParameters Commands::filterMostAppropriateDay(std::vector<DayParameters>& dates)
{
	if (dates.size() == 1)
	{
		return dates[0];
	}
	return (*std::min_element(dates.begin(), dates.end(), [](const DayParameters& first, const DayParameters& second) { return (first.getWind() < second.getWind()
		|| (first.getWind() == second.getWind() && first.getHumidity() < second.getHumidity()));}));
	
}

std::vector<std::vector<std::string>> Commands::fillTable()
{
	std::vector<std::vector<std::string>> table;
	table = fillParametersTable();
	if (getDays().empty())
	{
		fillEmptyTable(table);
		return table;
	}
	fillParametersColumn(table);
	std::vector<DayParameters> filtredDays = filterAcceptableDays();
	if (!filtredDays.empty())
	{
		DayParameters day = filterMostAppropriateDay(filtredDays);
		fillLaunchDayColumn(table, day);
	}
	else
	{
		fillEmptyColumn(table);
	}
	return table;
}

std::vector<std::vector<std::string>> Commands::fillParametersTable()
{
	std::vector<std::vector<std::string>> table;
	std::vector<std::string> line{"Parameter", "Average value","Max value","Min value","Median value","Launch Day" };
	table.push_back(line);
	table.push_back({ "Temperature (C)" });
	table.push_back({ "Wind speed (m/s)" });
	table.push_back({ "Humidity (%)" });
	table.push_back({ "Precipitation (%)" });
	table.push_back({ "Lightning (y/n)" });
	table.push_back({ "Clouds" });
	return table;
}

void Commands::createDataFile()
{
	std::ofstream file2("WeatherReport.csv", std::ofstream::trunc);
	if (!file2.is_open()) {
		std::cout << "Failed to create the file." << std::endl;
		return;
	}
	std::vector<std::vector<std::string>> table = fillTable();
	writeTableInFile(table, file2);
	file2.close();
		
}

void Commands::writeTableInFile(std::vector<std::vector<std::string>>& table,std::ofstream& file)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			file << table[i][j] << ",";
		}
		file << table[i][5]<<std::endl;
	}
}

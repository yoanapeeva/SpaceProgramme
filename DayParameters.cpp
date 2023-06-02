#include "DayParameters.h"

DayParameters::DayParameters()
{
	day = 1;
	temperature = 0;
	wind = 0;
	humidity = 0;
	precipitation = 0;
	lightning = false;
	type = CloudType::Cumulus;
}


void DayParameters::setDay(int day)
{
	if (day > 0 && day < 32)
	{
		this->day = day;
	}
	else
	{
		throw std::out_of_range("The date is incorrect.");
	}
}

void DayParameters::setTemperature(int temperature)
{
	this->temperature = temperature;
}

void DayParameters::setWind(int wind)
{
	if (wind >= 0)
	{
		this->wind = wind;
	}
	else
	{
		throw std::out_of_range("The speed of wind couldn`t be negative.");
	}
}

void DayParameters::setHumidity(int humidity)
{
	if (humidity >= 0&&humidity<=100)
	{
		this->humidity = humidity;
	}
	else
	{
		throw std::out_of_range("The percentage of the humidity couldn`t be negative.");
	}
}

void DayParameters::setPrecipitation(int precipitation)
{
	if (precipitation >= 0&&precipitation<=100)
	{
		this->precipitation = precipitation;
	}
	else
	{
		throw std::out_of_range("The percentage of the humidity couldn`t be negative.");
	}
}

void DayParameters::setLightning(std::string lightning)
{

	if (HelperFunction::isYes(lightning))
	{
		this->lightning = true;
	}
	else if (HelperFunction::isNo(lightning))
	{
		this->lightning = false;
	}
	else
	{
		throw std::invalid_argument("Invalid information for lightning storm.");
	}

}

void DayParameters::setCloudsType(std::string type)
{
	CloudType t;
	t = Cloud::setCloud(type);
	this->type = t;

}

int DayParameters::getDay() const
{
	return this->day;
}

int DayParameters::getTemperature() const
{
	return this->temperature;
}

int DayParameters::getWind() const
{
	return this->wind;
}

int DayParameters::getHumidity() const
{
	return this->humidity;
}

int DayParameters::getPrecipitation() const
{
	return this->precipitation;
}

bool DayParameters::getLightning() const
{
	return this->lightning;
}

CloudType DayParameters::getCloudType() const
{
	return this->type;
}

bool DayParameters::isAcceptable()
{
	return (temperature >= 2 && temperature <= 31 && wind <= 10 && humidity <= 60 && precipitation == 0 &&
		!lightning && type != CloudType::Cumulus && type != CloudType::Nimbus);
}

std::string DayParameters::convertLightningToString()
{
	if (getLightning())
	{
		return "Yes";
	}
	return "No";	
}

std::string DayParameters::convertCloudTypeToToString()
{
	return Cloud::convertCloudTypeToString(getCloudType());
}


std::istream& operator>>(std::istream& is, DayParameters& day)
{
	std::cout << "Please enter the data for the day : " << std::endl;

	enterDate(is, day);
	enterTemperaturre(is, day);
	enterWind(is, day);
	enterHumidity(is, day);
	enterPrecipitation(is, day);
	enterLightning(is, day);
	enterCloudType(is, day);
	
	return is;
}

void enterDate(std::istream& is, DayParameters& day)
{

	std::cout << "Date of July : " << std::endl;
	bool tmp = true;
	while (tmp)
	{
		int date;
		is >> date;
		try
		{
			day.setDay(date);
			tmp = false;
		}
		catch (std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << "Please enter the date again : " << std::endl;
		}
	}

}

void enterTemperaturre(std::istream& is, DayParameters& day)
{

	std::cout << "Temperature (C) : " << std::endl;
	int temperature;
	is >> temperature;
	day.setTemperature(temperature);
}

void enterWind(std::istream& is, DayParameters& day)
{
	bool tmp = true;
	std::cout << "Wind speed (m/s) : " << std::endl;
	while (tmp)
	{
		int windSpeed;
		is >> windSpeed;
		try
		{
			day.setWind(windSpeed);
			tmp = false;
		}
		catch (std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << "Please enter the speed of the wind again : " << std::endl;
		}
	}
}

void enterHumidity(std::istream& is, DayParameters& day)
{
	bool tmp = true;

	std::cout << "Humidity (%) : " << std::endl;

	while (tmp)
	{
		int humidity;
		is >> humidity;
		try
		{
			day.setHumidity(humidity);
			tmp = false;
		}
		catch (std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << "Please enter the percentage of the humidity again : " << std::endl;
		}
	}
}

void enterPrecipitation(std::istream& is, DayParameters& day)
{
	bool tmp = true;

	std::cout << "Precipitation (%) : " << std::endl;
	while (tmp)
	{
		int precipitation;
		is >> precipitation;
		try
		{
			day.setPrecipitation(precipitation);
			tmp = false;
		}
		catch (std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << "Please enter the percentage of the precipitation again : " << std::endl;
		}

	}
}

void enterLightning(std::istream& is, DayParameters& day)
{
	bool tmp = true;

	std::cout << "Lightning (y/n) : " << std::endl;

	while (tmp)
	{
		std::string lightning;
		is >> lightning;
		try
		{
			day.setLightning(lightning);
			tmp = false;
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << "Please enter if there will be lighning storm again : " << std::endl;
		}
	}
}

void enterCloudType(std::istream& is, DayParameters& day)
{
	bool tmp = true;

	std::cout << "Type of clouds in the sky : " << std::endl;

	while (tmp)
	{
		std::string cloud;
		is >> cloud;

		try
		{
			day.setCloudsType(cloud);
			tmp = false;
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << "Please enter the type of clouds again : " << std::endl;
		}
	}
}

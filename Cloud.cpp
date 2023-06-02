#include "Cloud.h"

CloudType Cloud::setCloud(std::string type)
{
	if (HelperFunction::isSameWords(type, "Cumulus"))
	{
		return CloudType::Cumulus;
	}
	else if (HelperFunction::isSameWords(type, "Stratus"))
	{
		return CloudType::Stratus;
	}
	else if (HelperFunction::isSameWords(type, "Nimbus"))
	{
		return CloudType::Nimbus;
	}
	else if (HelperFunction::isSameWords(type, "Cirrus"))
	{
		return CloudType::Cirrus;
	}
	else
	{
		throw std::invalid_argument("Invalid type of clouds");
	}
}

std::string Cloud::convertCloudTypeToString(CloudType type)
{
	switch (type)
	{
	case CloudType::Cumulus:
		return "Cumulus";
		break;
	case CloudType::Stratus:
		return "Stratus";
		break;
	case CloudType::Nimbus:
		return "Nimbus";
		break;
	case CloudType::Cirrus:
		return "Cirrus";
		break;
	}
}

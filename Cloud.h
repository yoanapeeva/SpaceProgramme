#pragma once
#include<iostream>
#include "HelperFunction.h"

//enum class for cloud type
enum class CloudType
{
	Cumulus,
	Stratus,
	Nimbus,
	Cirrus
};
class Cloud
{
private:
	CloudType type;
public:

	static CloudType setCloud(std::string type);
	static std::string convertCloudTypeToString(CloudType type);
};

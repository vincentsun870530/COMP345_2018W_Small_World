#pragma once
#include <vector>
#include <string>
#include <stdbool.h>

class Region
{
public:
	Region();
	~Region();
	void setRegionID(int n);
private:
	int regionID = 65535;
	int  owner = 0;
	int numCuRace = 0;
	int  numDeRace = 0;
	std::string regionChar = "";
	std::string cuRaceName = "";
	std::string deRaceName = "";
	bool hasLostTribe = 0;
};


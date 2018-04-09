#pragma once
#include "Observer.h"
#include <string>
#include <vector>

class ObserverPhase :
	public Observer
{
public:
	ObserverPhase();
	~ObserverPhase();

	virtual void update(Players * inputPlayer);
	virtual void update(Region * inputRegion);
	void showStatus();

private:
	std::string programStatus;
	int currentPlayerID;
	int currentInHandActiveRaceSolider;
	int currentInHandDeclinedRaceSolider;
	std::string activeRaceName;
	std::string activePowerName;
	std::string declinedRaceName;
	std::vector<int> currentControlRegionList;
	std::vector<int> turnConquerRegionList;
	std::vector<int> adjacentRegionList;
	std::vector<int> activeRaceControlRegionList;
	std::vector<int> declinedRaceControlRegionList;
	int playerTotalCoins;
};


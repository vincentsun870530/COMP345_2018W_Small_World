#include "ObserverStatistics.h"
#include "Region.h"
#include "Map.h"

extern Map * ptPlayersMap;

ObserverStatistics::ObserverStatistics()
{
	set_observer_name("ObserverStatistics");
}

ObserverStatistics::ObserverStatistics(int playerNum)
{
	set_observer_name("ObserverStatistics");
	if (playerNum > 0)
	{
		for (int i = 0; i < playerNum+1; ++i)
			playerRegionShareList.push_back(0);

		playerRegionShareList.at(playerNum) = ptPlayersMap->getNumRegion();
	}
}


ObserverStatistics::~ObserverStatistics()
{
}

void ObserverStatistics::update(Region * inputRegion)
{
	int formerOwner = inputRegion->get_former_owner();
	int currentOwner = inputRegion->get_owner();

	if (formerOwner == -1) 
		playerRegionShareList.at(playerRegionShareList.size()-1) = playerRegionShareList.at(playerRegionShareList.size()-1) - 1;
	else playerRegionShareList.at(formerOwner) = playerRegionShareList.at(formerOwner) - 1;

	if (currentOwner == -1)
		playerRegionShareList.at(playerRegionShareList.size() - 1) = playerRegionShareList.at(playerRegionShareList.size() - 1) + 1;
	else playerRegionShareList.at(currentOwner) = playerRegionShareList.at(currentOwner) + 1;
}


void ObserverStatistics::showStatus()
{
	std::cout << "\n\n*****************************************************************\n" << std::endl;
	std::cout << "Players control regions bar chart : \n" << std::endl;

	for (int i = 0; i < playerRegionShareList.size(); ++i)
	{
		std::cout << "Player " << i << " : ";
		for (int j = 0; j < playerRegionShareList.at(i); ++j)
			std::cout << "&";
		std::cout << " " << std::endl;
	}
	
	std::cout << "\n*****************************************************************\n\n" << std::endl;

}

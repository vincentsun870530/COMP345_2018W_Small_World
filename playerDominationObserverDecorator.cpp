#include "playerDominationObserverDecorator.h"
#include "Players.h"
#include "Map.h"

extern vector<Players *> * ptPlayersPointerList;
extern Map * ptPlayersMap;

playerDominationObserverDecorator::playerDominationObserverDecorator()
{
	set_observer_name("playerDominationObserverDecorator");
}


playerDominationObserverDecorator::~playerDominationObserverDecorator()
{
}

playerDominationObserverDecorator::playerDominationObserverDecorator(Observer * inputObserver) : ObserverDecorator(inputObserver)
{
	set_observer_name("playerDominationObserverDecorator");
	playerRegionSharePercentage.resize(static_cast<int>(ptPlayersPointerList->size()) +1);
	playerRegionShareList.resize(static_cast<int>(ptPlayersPointerList->size()) +1);

	for(int i = 0; i < static_cast<int>(playerRegionSharePercentage.size()); ++i)
	{
		playerRegionSharePercentage.at(i) = 0;
		playerRegionShareList.at(i) = 0;
	}
}

void playerDominationObserverDecorator::update(Players * inputPlayer)
{
	ObserverDecorator::update(inputPlayer);
	
}
void playerDominationObserverDecorator::update(Region * inputRegion)
{
	int formerOwner = inputRegion->get_former_owner();
	int currentOwner = inputRegion->get_owner();

	if (formerOwner == -1)
		playerRegionShareList.at(static_cast<int>(playerRegionShareList.size()) - 1) = playerRegionShareList.at(static_cast<int>(playerRegionShareList.size()) - 1) - 1;
	else playerRegionShareList.at(formerOwner) = playerRegionShareList.at(formerOwner) - 1;

	if (currentOwner == -1)
		playerRegionShareList.at(static_cast<int>(playerRegionShareList.size()) - 1) = playerRegionShareList.at(static_cast<int>(playerRegionShareList.size()) - 1) + 1;
	else playerRegionShareList.at(currentOwner) = playerRegionShareList.at(currentOwner) + 1;

	for (int i = 0; i < static_cast<int>(playerRegionShareList.size()); ++i)
	{
		playerRegionSharePercentage.at(i) = 100 * static_cast<double>(playerRegionShareList.at(i)) / (ptPlayersMap->getNumRegion());
	}

	playerRegionSharePercentage.at(static_cast<int>(playerRegionShareList.size()) - 1) = 100 + playerRegionSharePercentage.at(static_cast<int>(playerRegionShareList.size()) - 1);
}
void playerDominationObserverDecorator::showStatus()
{
	std::cout << "\nView of Player Domination Observer Decorator\n" << endl;

	ObserverDecorator::showStatus();

	for(int i = 0; i < static_cast<int>(playerRegionSharePercentage.size()); ++i)
	{
		std::cout << "\nPlayer " << i << " controls " << playerRegionSharePercentage.at(i) << "% of total regions." << endl;
	}

	std::cout << "\n**********************************************************************************\n" << endl;
}

void playerDominationObserverDecorator::updatePercentage(Players * inputPlayer)
{
	return;
	/*int tempRegionSubtotal = 0;
	tempRegionSubtotal = inputPlayer->get_controlled_region_list().size() + inputPlayer->get_turn_region_conquer_list().size();
	
	int playerID = inputPlayer->get_id_player();

	if (playerID != -1)
	{
		playerRegionSharePercentage.at(playerID) = (static_cast<double>(tempRegionSubtotal)) / (ptPlayersMap->getNumRegion());
	}*/
}
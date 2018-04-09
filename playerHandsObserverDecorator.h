#pragma once
#include "ObserverDecorator.h"
#include <vector>

class playerHandsObserverDecorator :
	public ObserverDecorator
{
public:
	playerHandsObserverDecorator();
	~playerHandsObserverDecorator();

	playerHandsObserverDecorator(Observer *);
	void update(Players* inputPlayer);
	void update(Region* inputRegion);
	void showStatus();

private:
	std::vector<int> playerInHandCurrentRaceSoliderVector;
	std::vector<int> playerInHandDeclinedRaceSoliderVector;
	std::vector<int> playerInHandTrollLairsVector;
	std::vector<int> playerInHandFortressesVector;
	std::vector<int> playerInHandEncampmentsVector;
	std::vector<int> playerInHandHolesInTheGroundVector;
	std::vector<int> playerInHandHeroesVector;
	std::vector<int> playerInHandDragonVector;
};


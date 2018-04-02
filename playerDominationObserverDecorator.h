#pragma once
#include "ObserverDecorator.h"
#include <vector>

class playerDominationObserverDecorator :
	public ObserverDecorator
{
public:
	playerDominationObserverDecorator();
	playerDominationObserverDecorator(Observer *);
	void update(Players* inputPlayer);
	void update(Region* inputRegion);
	void showStatus();
	~playerDominationObserverDecorator();
	void updatePercentage(Players * inputPlayer);

private:
	std::vector<double> playerRegionSharePercentage;
	std::vector<int> playerRegionShareList;
};


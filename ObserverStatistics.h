#pragma once
#include "Observer.h"
#include <vector>


class ObserverStatistics :
	public Observer
{
public:
	ObserverStatistics();
	ObserverStatistics(int playerNum);
	~ObserverStatistics();

	void update(Region * inputRegion);
	void update(Players * inputPlayer) { return; };

	void showStatus();

private:
	std::vector<int> playerRegionShareList;

};


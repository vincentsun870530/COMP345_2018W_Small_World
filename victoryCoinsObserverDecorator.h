#pragma once
#include "ObserverDecorator.h"
#include <vector>


class victoryCoinsObserverDecorator :
	public ObserverDecorator
{
public:
	victoryCoinsObserverDecorator();

	victoryCoinsObserverDecorator(Observer *);

	~victoryCoinsObserverDecorator();

	virtual void update(Players * inputPlayer);
	virtual void update(Region * inputRegion);
	virtual void showStatus();

private:
	std::vector<int> playerVictoryCoinsList;
};


#pragma once
#include "Observer.h"
#include <string>


class basicGameStasticsObserver :
	public Observer
{
public:
	basicGameStasticsObserver();
	~basicGameStasticsObserver();

	virtual void update(Players * inputPlayer);
	virtual void update(Region * inputRegion);
	virtual void showStatus();

private:
	int gameTurnMarker = 0;
	
};


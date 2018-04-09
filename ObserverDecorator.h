#pragma once
#include "Observer.h"


class ObserverDecorator :
	public Observer
{
public:
	ObserverDecorator();
	ObserverDecorator(Observer *);
	~ObserverDecorator();

	virtual void update(Players * inputPlayer);
	virtual void update(Region * inputRegion);
	virtual void showStatus();

private:
	Observer * basicObserver;
};


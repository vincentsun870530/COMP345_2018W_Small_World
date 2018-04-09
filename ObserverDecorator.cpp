#include "ObserverDecorator.h"



ObserverDecorator::ObserverDecorator()
{
	set_observer_name("ObserverDecorator");
}


ObserverDecorator::~ObserverDecorator()
{
}

ObserverDecorator::ObserverDecorator(Observer * inputBasicObserver)
{
	set_observer_name("ObserverDecorator");
	basicObserver = inputBasicObserver;
}

void ObserverDecorator::update(Players * inputPlayer)
{
	basicObserver->update(inputPlayer);
}
void ObserverDecorator::update(Region * inputRegion)
{
	return;
}
void ObserverDecorator::showStatus()
{
	basicObserver->showStatus();
}
#include "coinObserverDecorator.h"

coinObserverDecorator::coinObserverDecorator()
{
}


coinObserverDecorator::~coinObserverDecorator()
{
}

coinObserverDecorator::coinObserverDecorator(PlayerObserver * observer) : Decorator(observer) {};

void coinObserverDecorator::update()
{
	this->player_observer->update();
	cout << "coin ******" << coin;
}

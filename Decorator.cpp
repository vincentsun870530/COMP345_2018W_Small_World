#include "Decorator.h"

Decorator::Decorator()
{
}

Decorator::Decorator(PlayerObserver* player_observer) : player_observer(player_observer)
{
	
}

Decorator::~Decorator()
{
}

void Decorator::update()
{
	player_observer->display();

}

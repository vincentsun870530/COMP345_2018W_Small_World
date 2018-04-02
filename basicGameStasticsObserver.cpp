#include "basicGameStasticsObserver.h"
#include "Players.h"


basicGameStasticsObserver::basicGameStasticsObserver()
{
	set_observer_name("basicGameStasticsObserver");
}


basicGameStasticsObserver::~basicGameStasticsObserver()
{
}


void basicGameStasticsObserver::update(Players * inputPlayer)
{
	gameTurnMarker = inputPlayer->get_game_turn_marker();
}

void basicGameStasticsObserver::update(Region * inputRegion)
{
	return;
}

void basicGameStasticsObserver::showStatus()
{
	std::cout << "\n\n************************************************************\n" << endl;
	std::cout << " View of basicGameStasticsObserver "  << endl;
	std::cout << "This is the " << gameTurnMarker << " turn of the game. \n" << endl;
}
#include "victoryCoinsObserverDecorator.h"
#include "Players.h"
#include "Map.h"

extern vector<Players *> * ptPlayersPointerList;
extern Map * ptPlayersMap;


victoryCoinsObserverDecorator::victoryCoinsObserverDecorator()
{
	set_observer_name("victoryCoinsObserverDecorator");
}


victoryCoinsObserverDecorator::~victoryCoinsObserverDecorator()
{
}

victoryCoinsObserverDecorator::victoryCoinsObserverDecorator(Observer * inputObserver) :  ObserverDecorator(inputObserver)
{
	set_observer_name("victoryCoinsObserverDecorator");
	playerVictoryCoinsList.resize(static_cast<int>(ptPlayersPointerList->size()));
	for(int i = 0; i < static_cast<int>(playerVictoryCoinsList.size()); i++)
	{
		playerVictoryCoinsList.at(i) = 0;
	}
}

void victoryCoinsObserverDecorator::update(Players * inputPlayer)
{
	ObserverDecorator::update(inputPlayer);

	int IDplayer = inputPlayer->get_id_player();

	playerVictoryCoinsList.at(IDplayer) = inputPlayer->get_player_total_coins();
}

void victoryCoinsObserverDecorator::update(Region * inputRegion)
{
	return;
}

void victoryCoinsObserverDecorator::showStatus()
{
	std::cout << "View of Victory Coins Observer Decorator \n" << endl;

	ObserverDecorator::showStatus();

	for (int i = 0; i < static_cast<int>(playerVictoryCoinsList.size()); ++i)
	{
		std::cout << "Player " << i << " has " << playerVictoryCoinsList.at(i) << " Victory coins in hand." << endl;
	}
}

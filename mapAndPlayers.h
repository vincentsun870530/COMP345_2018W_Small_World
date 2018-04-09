#pragma once
#include "Map.h"
#include "MapLoader.h"
#include "Players.h"
#include "Observer.h"

extern int numberOfPlayers;
extern vector<Players *> * ptPlayersPointerList;
extern Observer * ObserverForPlayers;

class mapAndPlayers
{
public:
	mapAndPlayers();
	~mapAndPlayers();

	Map * creatMap();

	void setupMapAndPlayers();

	vector<Players *> *  creatPlayers();

	void printPlayersList(vector<Players *> * const pointerPlayersPointerList) const;
};


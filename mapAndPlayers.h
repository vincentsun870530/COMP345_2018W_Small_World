#pragma once
#include "Map.h"
#include "MapLoader.h"
#include "Players.h"

extern int numberOfPlayers;
extern vector<Players *> * ptPlayersPointerList;

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


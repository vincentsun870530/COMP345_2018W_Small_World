#pragma once

#include "Map.h"
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class MapLoader
{

public:
	MapLoader() { numOfPlayers = (int)2; };
	MapLoader(int numPlayer) { numOfPlayers = numPlayer; };
	~MapLoader();
	Map* loadMap(bool interactive);
private:
	int numOfPlayers;
};


#include "mapAndPlayers.h"
#include "Observer.h"
#include "ObserverStatistics.h"

int numberOfPlayers = 0;
Map * ptPlayersMap = nullptr;
extern vector<Players *> * ptPlayersPointerList = nullptr;
extern Observer * ObserverForPlayers = nullptr;


mapAndPlayers::mapAndPlayers()
{
}


mapAndPlayers::~mapAndPlayers()
{
}

Map* mapAndPlayers::creatMap()
{
	// set a flag for try catch block
	bool goInCatchBlock;

	do {
		try {
			goInCatchBlock = false;
			cout << "Please input the number of players (2-5):  " << endl;
			cin >> numberOfPlayers;
			if((numberOfPlayers < 2) || (numberOfPlayers > 5))
			{
				throw runtime_error("Exception Input be a number and >=2 or <=5");

			}
		}catch(runtime_error& ex)
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			goInCatchBlock = true;
		}
	} while (goInCatchBlock);

	MapLoader maploader1(numberOfPlayers);

	Map* map2 = maploader1.loadMap(true);

	return map2;
}

vector<Players *> *  mapAndPlayers::creatPlayers()
{
	Players * tempPlayer = nullptr;

	vector<Players *>  * tempPlayersVector (new vector<Players *>);

	for(int i = 0; i < numberOfPlayers; i++)
	{
		tempPlayer = new Players();
		tempPlayersVector->push_back(tempPlayer);
		tempPlayersVector->at(i)->set_id_player(i);
	}

	return tempPlayersVector;
}


void mapAndPlayers::setupMapAndPlayers()
{
	ptPlayersMap = creatMap();
	ptPlayersPointerList = creatPlayers();

	ObserverForPlayers = new ObserverStatistics(static_cast<int>(ptPlayersPointerList->size()));

	if (ObserverForPlayers == nullptr)
	{
		std::cout << "ObserverForPlayers is nullptr " << endl;
		system("pause");
		exit(0);
	}
		
	for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
	{
		ptPlayersMap->getRegion(i)->attach(ObserverForPlayers);
	}
}

void mapAndPlayers::printPlayersList(vector<Players *> * const pointerPlayersPointerList) const
{
	cout << "We have " << pointerPlayersPointerList->size() << " players. " << endl;

	for (auto p = pointerPlayersPointerList->begin(); p != pointerPlayersPointerList->end(); p++)
	{
		std::cout << " Player " << (*p)->get_id_player() << std::endl;
	}
	cout << endl;
}
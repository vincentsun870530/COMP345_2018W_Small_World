#include "RandomStrategy.h"
#include "Players.h"
#include <algorithm>
#include "Map.h"
#include <time.h> 
#include <stdlib.h> 

extern std::vector<RaceBanner *> * raceBannerVector;
extern int gameTurnMarker;
extern Map* ptPlayersMap;

RandomStrategy::RandomStrategy()
{
}


RandomStrategy::~RandomStrategy()
{
}


int RandomStrategy::strategyDeclineDecision(Players* inputPlayer)
{
	int randValue = 0;
	srand(time(0));
	randValue = rand();

	if (randValue >= (RAND_MAX / 2)) return 1;
	else return 0;
}

int RandomStrategy::strategyRaceSelection(Players* inputPlayer)
{
	for (auto iter = raceBannerVector->begin(); (iter != raceBannerVector->end()); ++iter)
	{
		if ((*iter)->is_available()) return (*iter)->get_id_race();
	}

	std::cout << "Players has used up all the races, system has to exit !" << endl;
	system("pause");
	exit(0);
}

int RandomStrategy::strategyRegionSelection(Players* inputPlayer)
{
	if (!(inputPlayer))
	{
		std::cout << "inputPlayer null pointer form int AggressiveStrategy::strategyRegionSelection(Players* inputPlayer) " << endl;
		exit(0);
	}

	vector<int> tempRegionIDVector;

	if (gameTurnMarker == 0)
	{
		tempRegionIDVector = inputPlayer->getFirstTimeAvailableAttackRegion();

		random_shuffle(tempRegionIDVector.begin(), tempRegionIDVector.end());

		return (*tempRegionIDVector.begin());
	}

	else
	{
		tempRegionIDVector = inputPlayer->getAvailableAttackRegion();

		random_shuffle(tempRegionIDVector.begin(), tempRegionIDVector.end());

		for (auto iter = tempRegionIDVector.begin(); iter != tempRegionIDVector.end(); )
		{
			if (!((!(inputPlayer->get_current_race()->getRaceName() == ptPlayersMap->getRegion(*iter)->get_cu_race_name())) &&
				(((inputPlayer->isAttckableRegion(*iter)) && (inputPlayer->get_current_race()->regionAttackAprove(*iter)) && (inputPlayer->get_current_power()->regionAttackAprove(*iter))))))
				iter = tempRegionIDVector.erase(iter);
			else 
				++iter;
		}
		random_shuffle(tempRegionIDVector.begin(), tempRegionIDVector.end());

		return (*tempRegionIDVector.begin());
	}
}
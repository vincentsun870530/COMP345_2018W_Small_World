#include "DefensiveStrategy.h"
#include "Players.h"
#include <algorithm>
#include "Map.h"

extern std::vector<RaceBanner *> * raceBannerVector;
extern int gameTurnMarker;
extern Map* ptPlayersMap;


DefensiveStrategy::DefensiveStrategy()
{
}


DefensiveStrategy::~DefensiveStrategy()
{
}


int DefensiveStrategy::strategyDeclineDecision(Players* inputPlayer)
{
	if (inputPlayer->get_in_hand_solider_current_race() <= 1) return 1;
	else return 0;
}

int DefensiveStrategy::strategyRaceSelection(Players* inputPlayer)
{
	for (auto iter = raceBannerVector->begin(); (iter != raceBannerVector->end()); ++iter)
	{
		if ((*iter)->is_available()) return (*iter)->get_id_race();
	}

	std::cout << "Players has used up all the races, system has to exit !" << endl;
	system("pause");
	exit(0);
}

int DefensiveStrategy::strategyRegionSelection(Players* inputPlayer)
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

		for (auto iter = tempRegionIDVector.begin(); iter != tempRegionIDVector.end(); ++iter)
		{
			if (ptPlayersMap->getRegion(*iter)->get_owner() != -1)
				return (*iter);
		}
		return (*tempRegionIDVector.begin());
	}

	else
	{
		tempRegionIDVector = inputPlayer->getAvailableAttackRegion();

		random_shuffle(tempRegionIDVector.begin(), tempRegionIDVector.end());

		for (auto iter = tempRegionIDVector.begin(); iter != tempRegionIDVector.end(); ++iter)
		{
			if ((ptPlayersMap->getRegion(*iter)->get_owner() != -1) &&
				(!(inputPlayer->get_current_race()->getRaceName() == ptPlayersMap->getRegion(*iter)->get_cu_race_name())) &&
				(((inputPlayer->isAttckableRegion(*iter)) && (inputPlayer->get_current_race()->regionAttackAprove(*iter)) && (inputPlayer->get_current_power()->regionAttackAprove(*iter)))))
				return (*iter);
		}
		return (*tempRegionIDVector.begin());
	}
}
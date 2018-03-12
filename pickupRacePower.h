#pragma once
#include <vector>
#include "Players.h"
#include "RaceBanner/RaceBanner.h"
#include "Badges/Badges.h"

void showALLRacesBadges();
void show6OrLessAvailableRacesBadges();
int get_correct_inputNumberOfChoice(int i, int k);
int getNumberInputForRace();
int currentMaxNumberOfRace();

class pickupRacePower
{
public:
	pickupRacePower();
	~pickupRacePower();

	void action();

//private:
//	int i = 0;
};


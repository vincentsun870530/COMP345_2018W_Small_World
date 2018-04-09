#pragma once
#include "Strategy.h"
class RandomStrategy :
	public Strategy
{
public:
	RandomStrategy();
	~RandomStrategy();

	int strategyDeclineDecision(Players*);
	int strategyRaceSelection(Players*);
	int strategyRegionSelection(Players*);
};


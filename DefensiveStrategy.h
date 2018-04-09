#pragma once
#include "Strategy.h"
class DefensiveStrategy :
	public Strategy
{
public:
	DefensiveStrategy();
	~DefensiveStrategy();

	int strategyDeclineDecision(Players*);
	int strategyRaceSelection(Players*);
	int strategyRegionSelection(Players*);
};


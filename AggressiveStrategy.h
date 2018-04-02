#pragma once
#include "Strategy.h"
class AggressiveStrategy :
	public Strategy
{
public:
	AggressiveStrategy();
	~AggressiveStrategy();

	int strategyDeclineDecision(Players*);
	int strategyRaceSelection(Players*);
	int strategyRegionSelection(Players*);

};


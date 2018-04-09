#pragma once
#include "Strategy.h"
class ModerateStrategy :
	public Strategy
{
public:
	ModerateStrategy();
	~ModerateStrategy();

	int strategyDeclineDecision(Players*);
	int strategyRaceSelection(Players*);
	int strategyRegionSelection(Players*);
};


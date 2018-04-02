#pragma once


class  Players;


class Strategy
{
public:
	Strategy();
	~Strategy();

	virtual int strategyDeclineDecision(Players*) = 0;
	virtual int strategyRaceSelection(Players*) = 0;
	virtual int strategyRegionSelection(Players*) = 0;
};


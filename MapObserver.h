#pragma once
#include "Observer.h"
#include "Players.h"

class MapObserver : public Observer
{
public:
	//Players* _playerdata;
	vector<Players*> playerPrecentageData;
	Region* currentRegion;
	double precentage;
	MapObserver();
	MapObserver(vector<Players*>);
	~MapObserver();
	void update() override;
	void display() override;
};


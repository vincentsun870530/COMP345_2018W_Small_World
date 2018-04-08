#include "MapObserver.h"



MapObserver::MapObserver()
{
}


MapObserver::~MapObserver()
{
	for (int i = 0; i < playerPrecentageData.size(); i++) {
		playerPrecentageData[i]->detach(this);
	}
}

MapObserver::MapObserver(vector<Players*> playerPrecentageData) : playerPrecentageData(playerPrecentageData)
{
	for (int i = 0; i < playerPrecentageData.size(); i++) {
		playerPrecentageData[i]->attach(this);
	}
	precentage = 0;
};

void MapObserver::update()
{
	
	this->display();
}

void MapObserver::display()
{
	cout << "Small Domination View:" << endl;
	for (int i = 0; i < playerPrecentageData.size(); i++) {
		playerPrecentageData[i]->setPrecentageRegionRatio();
		cout << playerPrecentageData[i]->get_precentage() << endl;
	}
}


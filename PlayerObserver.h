#pragma once
#include <iostream>
#include "Observer.h"
#include "Players.h"
using namespace std;

class PlayerObserver : public Observer
{
private:
	Players *_playerdata;

public:
	PlayerObserver();
	PlayerObserver(Players *playerdata);
	~PlayerObserver();
	void update() override;
	void display();
};


#pragma once
#include "PlayerObserver.h"

class Decorator : public PlayerObserver
{
public:
	PlayerObserver * player_observer;
	Decorator();
	Decorator(PlayerObserver * player_observer);
	~Decorator();
	void update() override;
};


#pragma once
#include "PlayerObserver.h"
#include "Decorator.h"

class coinObserverDecorator : public Decorator
{
public:
	coinObserverDecorator();
	coinObserverDecorator(PlayerObserver * observer);
	~coinObserverDecorator();
	void update() override;
	int coin;
};


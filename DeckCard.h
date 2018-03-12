#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Badges/Badges.h"
#include "RaceBanner/RaceBanner.h"

class DeckCard {
public:
	DeckCard();

	DeckCard(const Badges &badges_, const RaceBanner &raceBanner_);

	~DeckCard();

	void showDeckCard();

	Badges &getBadges_();

	void setBadges_(const Badges &badges_);

	RaceBanner &getRaceBanner_();

	void setRaceBanner_(const RaceBanner &raceBanner_);

	const int getInitialToken();

private:
	Badges badges_;
	RaceBanner raceBanner_;
};


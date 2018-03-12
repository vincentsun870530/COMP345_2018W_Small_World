
#include "DeckCard.h"


DeckCard::DeckCard() {
}

DeckCard::DeckCard(const Badges &badges_, const RaceBanner &raceBanner_) : badges_(badges_), raceBanner_(raceBanner_) {}

Badges &DeckCard::getBadges_() {
	return badges_;
}

void DeckCard::setBadges_(const Badges &badges_) {
	DeckCard::badges_ = badges_;
}

RaceBanner &DeckCard::getRaceBanner_() {
	return raceBanner_;
}

void DeckCard::setRaceBanner_(const RaceBanner &raceBanner_) {
	DeckCard::raceBanner_ = raceBanner_;
}

const int DeckCard::getInitialToken() {
	return badges_.getTokenAmount_() + raceBanner_.getTokenAmount_();
}

DeckCard::~DeckCard() {
}

void DeckCard::showDeckCard() {
	std::cout << "DeckCardCombo: " << std::endl;
	raceBanner_.show();
	badges_.show();
}






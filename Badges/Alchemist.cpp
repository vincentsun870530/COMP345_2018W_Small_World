//
// Created by vince on 2018/2/9.
//

#include "Alchemist.h"

Alchemist::Alchemist() {
	setBadgesName_("Alchemist");
	setSpecialPowerDescription_("Collect 2 bonus Victory coins at the end of each turn");
	setTokenAmount_(4);
};

Alchemist::~Alchemist() {
};

int Alchemist::startSuperPowerForVictoryCoin(int VictoryCoin) {
	return (VictoryCoin + 1);
}

void Alchemist::startSuperPowerForToken(int tempToken) {
	Badges::startSuperPowerForToken(tempToken);
}

void Alchemist::show() {
	Badges::show();
};
//
// Created by vince on 2018/2/10.
//

#include "Elves.h"

Elves::Elves() : RaceBanner() {
    raceName_ = "Elves";
    racePowerDescription_ = "When the enemy conquers one of your Regions, you keep all your Elf tokens for redeployment at the end of current player's turn, rather than losing 1 Elf Token";
    tokenAmount_ = 6;
}

Elves::~Elves() {

}


void Elves::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Elves::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Elves::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Elves::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Elves::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Elves::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Elves::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Elves::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Elves::show() {
    RaceBanner::show();
}

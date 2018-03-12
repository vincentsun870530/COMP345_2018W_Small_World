//
// Created by vince on 2018/2/10.
//

#include "Trolls.h"

Trolls::Trolls() : RaceBanner() {
    raceName_ = "Trolls";
    racePowerDescription_ = "Place a Troll's Lair in each Region your Trolls occupy";
    tokenAmount_ = 5;
}

Trolls::~Trolls() {

}

Trolls::Trolls(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Trolls::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Trolls::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Trolls::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Trolls::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Trolls::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Trolls::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Trolls::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Trolls::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Trolls::show() {
    RaceBanner::show();
}

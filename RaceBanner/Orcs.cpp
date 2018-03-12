//
// Created by vince on 2018/2/10.
//

#include "Orcs.h"

Orcs::Orcs() : RaceBanner() {
    raceName_ = "Orcs";
    racePowerDescription_ = "Each non-empty Region your orcs conquered this turn is worth 1 bonus Victory coin, at the end of your turn";
    tokenAmount_ = 5;
}

Orcs::~Orcs() {

}

Orcs::Orcs(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Orcs::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Orcs::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Orcs::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Orcs::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Orcs::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Orcs::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Orcs::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Orcs::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Orcs::show() {
    RaceBanner::show();
}

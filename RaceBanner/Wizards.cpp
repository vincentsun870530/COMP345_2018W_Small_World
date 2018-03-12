//
// Created by vince on 2018/2/10.
//

#include "Wizards.h"

Wizards::Wizards() : RaceBanner() {
    raceName_ = "Wizards";
    racePowerDescription_ = "Each Magic Region your Wizards occupy is worth 1 bonus Victory coin, at the end of your turn";
    tokenAmount_ = 5;
}

Wizards::~Wizards() {

}

Wizards::Wizards(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Wizards::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Wizards::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Wizards::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Wizards::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Wizards::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Wizards::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Wizards::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Wizards::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Wizards::show() {
    RaceBanner::show();
}

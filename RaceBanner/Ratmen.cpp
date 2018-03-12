//
// Created by vince on 2018/2/10.
//

#include "Ratmen.h"

Ratmen::Ratmen() : RaceBanner() {
    raceName_ = "Ratmen";
    racePowerDescription_ = "No Race benefit; their sheer number is enough";
    tokenAmount_ = 8;
}

Ratmen::~Ratmen() {

}

Ratmen::Ratmen(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Ratmen::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Ratmen::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Ratmen::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Ratmen::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Ratmen::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Ratmen::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Ratmen::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Ratmen::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Ratmen::show() {
    RaceBanner::show();
}

//
// Created by vince on 2018/2/10.
//

#include "Sorceres.h"

Sorceres::Sorceres() : RaceBanner() {
    raceName_ = "Sorcerers";
    racePowerDescription_ = "Once per turn per opponent......";
    tokenAmount_ = 5;
}

Sorceres::~Sorceres() {

}

Sorceres::Sorceres(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_)
        : RaceBanner(raceName_, racePowerDescription_, tokenAmount_) {

}

void Sorceres::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Sorceres::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Sorceres::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Sorceres::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Sorceres::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Sorceres::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Sorceres::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Sorceres::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Sorceres::show() {
    RaceBanner::show();
}

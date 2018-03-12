//
// Created by vince on 2018/2/10.
//

#include "Ghouls.h"

Ghouls::Ghouls() : RaceBanner() {

    raceName_ = "Ghouls";
    racePowerDescription_ = "Your Ghoul Tokens all stay on the map when going into Decline, instead of usual 1 token per region";
    tokenAmount_ = 5;

}

Ghouls::~Ghouls() {

}

Ghouls::Ghouls(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Ghouls::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Ghouls::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Ghouls::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Ghouls::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Ghouls::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Ghouls::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Ghouls::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Ghouls::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Ghouls::show() {
    RaceBanner::show();
}

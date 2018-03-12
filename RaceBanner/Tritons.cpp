//
// Created by vince on 2018/2/10.
//

#include "Tritons.h"

Tritons::Tritons() : RaceBanner() {
    raceName_ = "Tritons";
    racePowerDescription_ = "Your Tritons may conquer all Coastal Regions (those bordering a Sea or Lake) at a cost of 1 less Triton token than normal. A minmum of 1 Triton token is still required";
    tokenAmount_ = 6;
}

Tritons::~Tritons() {

}

Tritons::Tritons(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Tritons::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Tritons::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Tritons::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Tritons::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Tritons::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Tritons::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Tritons::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Tritons::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Tritons::show() {
    RaceBanner::show();
}

//
// Created by vince on 2018/2/10.
//

#include "Giants.h"

Giants::Giants() : RaceBanner() {
    raceName_ = "Giants";
    racePowerDescription_ = "Your Giants may conquer any Region adjacent to Mountain Region they occupy at a cost of 1 less Giant token than notmal. A minimum of 1 Giant token is still required.";
    tokenAmount_ = 6;
}

Giants::~Giants() {

}

Giants::Giants(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Giants::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Giants::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Giants::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Giants::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Giants::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Giants::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Giants::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Giants::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Giants::show() {
    RaceBanner::show();
}

//
// Created by vince on 2018/2/10.
//

#include "Humans.h"

Humans::Humans() : RaceBanner() {
    raceName_ = "Humans";
    racePowerDescription_ = "Each Farmland Region your Humans occupy is worth 1 bonus Victory coin, at the end of your turn";
    tokenAmount_ = 5;

}

Humans::~Humans() {

}

Humans::Humans(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_) : RaceBanner(
        raceName_, racePowerDescription_, tokenAmount_) {

}

void Humans::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Humans::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Humans::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Humans::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Humans::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Humans::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Humans::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Humans::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Humans::show() {
    RaceBanner::show();
}

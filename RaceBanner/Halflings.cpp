//
// Created by vince on 2018/2/10.
//

#include "Halflings.h"

Halflings::Halflings() : RaceBanner() {
    raceName_ = "Halfings";
    racePowerDescription_   = "Your Halfing tokens may enter the may through any Region of map, not just border ones. A Hole-in-the-ground will be placed in each of the first 2 Regions you conquer, making them immune to enemy conquests as well as racial and special power";
    tokenAmount_=6;

}

Halflings::~Halflings() {

}

Halflings::Halflings(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_)
        : RaceBanner(raceName_, racePowerDescription_, tokenAmount_) {

}

void Halflings::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Halflings::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Halflings::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Halflings::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Halflings::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Halflings::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Halflings::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Halflings::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Halflings::show() {
    RaceBanner::show();
}

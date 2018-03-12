//
// Created by vince on 2018/2/14.
//

#include "Pillaging.h"

Pillaging::Pillaging() : Badges() {
    badgesName_ = "Pillaging";
    specialPowerDescription_ = "Each non-empty Region you conquer this turn is worth 1 bonus Victory coin at turn's end.";
    tokenAmount_ =5;

}

Pillaging::Pillaging(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Pillaging::~Pillaging() {

}

void Pillaging::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Pillaging::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Pillaging::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Pillaging::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Pillaging::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Pillaging::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Pillaging::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Pillaging::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Pillaging::show() {
    Badges::show();
}

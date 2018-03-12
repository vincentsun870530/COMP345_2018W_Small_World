//
// Created by vince on 2018/2/14.
//

#include "Swamp.h"

Swamp::Swamp() : Badges() {
    badgesName_ = "Swamp";
    specialPowerDescription_ = "Collect 1 bonus Victory coin for each Swamp Region you occupy at turn's end.";
    tokenAmount_=4;
}

Swamp::Swamp(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_) : Badges(
        badgesName_, specialPowerDescription_, tokenAmount_) {

}

Swamp::~Swamp() {

}

void Swamp::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Swamp::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Swamp::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Swamp::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Swamp::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Swamp::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Swamp::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Swamp::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Swamp::show() {
    Badges::show();
}

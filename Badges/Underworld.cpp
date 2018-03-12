//
// Created by vince on 2018/2/14.
//

#include "Underworld.h"

Underworld::Underworld() : Badges() {
    badgesName_ = "Underworld";
    specialPowerDescription_ = "You may conquer any Region with a Cavern with 1 less Race token than normal. A minimum of 1 token is still required. All Regions with a Cavern are also considered adjacent to each other for your conquest purposes.";
    tokenAmount_ = 5;
}

Underworld::Underworld(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Underworld::~Underworld() {

}

void Underworld::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Underworld::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Underworld::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Underworld::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Underworld::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Underworld::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Underworld::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Underworld::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Underworld::show() {
    Badges::show();
}

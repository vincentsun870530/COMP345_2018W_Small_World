//
// Created by vince on 2018/2/14.
//

#include "Mounted.h"

Mounted::Mounted() : Badges() {
    badgesName_ = "Mounted";
    specialPowerDescription_ = "You may conquer any Hill or Farmland Region with 1 less Race token than normal. A minimum of 1 token is still required.";
    tokenAmount_ = 5;
}

Mounted::Mounted(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Mounted::~Mounted() {

}

void Mounted::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Mounted::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Mounted::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Mounted::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Mounted::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Mounted::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Mounted::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Mounted::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Mounted::show() {
    Badges::show();
}

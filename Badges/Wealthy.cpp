//
// Created by vince on 2018/2/14.
//

#include "Wealthy.h"

Wealthy::Wealthy() : Badges() {
    badgesName_ = "Wealthy";
    specialPowerDescription_ = "Collect 7 bonus Victory coins, once only, at the end of your first turn.";
    tokenAmount_ = 4;
}

Wealthy::Wealthy(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Wealthy::~Wealthy() {

}

void Wealthy::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Wealthy::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Wealthy::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Wealthy::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Wealthy::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Wealthy::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Wealthy::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Wealthy::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Wealthy::show() {
    Badges::show();
}

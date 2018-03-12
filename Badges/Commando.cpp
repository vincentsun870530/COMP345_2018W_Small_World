//
// Created by vince on 2018/2/13.
//

#include "Commando.h"

Commando::Commando() : Badges() {
        badgesName_ = "Commando";
        specialPowerDescription_ = "You may conquer any Region with 1 less Race token than normal. A minimum of 1 token is still required.";
        tokenAmount_ = 4;
}

Commando::Commando(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Commando::~Commando() {

}

void Commando::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Commando::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Commando::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Commando::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Commando::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Commando::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Commando::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Commando::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Commando::show() {
    Badges::show();
}

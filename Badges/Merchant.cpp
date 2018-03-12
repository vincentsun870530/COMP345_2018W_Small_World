//
// Created by vince on 2018/2/14.
//

#include "Merchant.h"

Merchant::Merchant() : Badges() {
    badgesName_= "Merchant";
    specialPowerDescription_ = "Collect 1 bonus Victory coin for any Region you occupy at turn's end.";
    tokenAmount_ =2;
}

Merchant::Merchant(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Merchant::~Merchant() {

}

void Merchant::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Merchant::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Merchant::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Merchant::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Merchant::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Merchant::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Merchant::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Merchant::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Merchant::show() {
    Badges::show();
}

//
// Created by vince on 2018/2/14.
//

#include "Flying.h"

Flying::Flying() : Badges() {
    badgesName_ = "Flying";
    specialPowerDescription_ = "You may conquer any Region of the map except Seas and Lakes. These Regions do not need to be adjacent or contiguous to ones you already occupy";
    tokenAmount_ = 5;
}

Flying::Flying(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_) : Badges(
        badgesName_, specialPowerDescription_, tokenAmount_) {

}

Flying::~Flying() {

}

void Flying::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Flying::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Flying::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Flying::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Flying::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Flying::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Flying::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Flying::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Flying::show() {
    Badges::show();
}

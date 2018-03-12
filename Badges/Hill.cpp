//
// Created by vince on 2018/2/14.
//

#include "Hill.h"

Hill::Hill() : Badges() {
    badgesName_ ="Hill";
    specialPowerDescription_ = "Collect 1 bonus Victory coin for each Hill Region you occupy at turn's end.";
    tokenAmount_ =4;

}

Hill::Hill(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_) : Badges(
        badgesName_, specialPowerDescription_, tokenAmount_) {

}

Hill::~Hill() {

}

void Hill::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Hill::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Hill::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Hill::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Hill::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Hill::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Hill::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Hill::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Hill::show() {
    Badges::show();
}

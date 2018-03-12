//
// Created by vince on 2018/2/14.
//

#include "Stout.h"

Stout::Stout() : Badges() {
    badgesName_ = "Stout";
    specialPowerDescription_ = "You may go In Decline at the end of a regular turn of conquests, after scoring, instead of spending an entire turn going into Decline.";
    tokenAmount_ = 4;
}

Stout::Stout(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_) : Badges(
        badgesName_, specialPowerDescription_, tokenAmount_) {

}

Stout::~Stout() {

}

void Stout::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Stout::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Stout::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Stout::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Stout::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Stout::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Stout::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Stout::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Stout::show() {
    Badges::show();
}

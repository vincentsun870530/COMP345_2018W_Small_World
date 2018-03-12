//
// Created by vince on 2018/2/14.
//

#include "Fortified.h"

Fortified::Fortified() : Badges() {
    badgesName_ = "Fortified";
    specialPowerDescription_ = "Once per turn, as long as your Fortified Race is active, you may place 1 Fortress in a Region you occupy. The Fortress is worth 1 bonus Victory coin at turn's end, unless you are In Decline. The Fortress also augments your Region's defense by 1 (just as if you had an additional Race token stationed there), even if you are In Decline. Remove the Fortress if you abandon the Region or when an enemy conquers it. There can only ever be a maximum of 1 Fortress per Region, and a maximum of 6 Fortresses on the map.";
    tokenAmount_=3;
}

Fortified::Fortified(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Fortified::~Fortified() {

}

void Fortified::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Fortified::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Fortified::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Fortified::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Fortified::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Fortified::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Fortified::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Fortified::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Fortified::show() {
    Badges::show();
}

//
// Created by vince on 2018/2/14.
//

#include "Heroic.h"

Heroic::Heroic() : Badges() {
    badgesName_ = "Heroic";
    specialPowerDescription_ ="At the end of your turn, place each of your 2 Heroes in 2 different Regions you occupy. These 2 Regions are immune to enemy conquests as well as to their racial and special powers until your Heroes move. Your Heroes disappear when you go into Decline.";
    tokenAmount_ = 5;
}

Heroic::Heroic(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_) : Badges(
        badgesName_, specialPowerDescription_, tokenAmount_) {

}

Heroic::~Heroic() {

}

void Heroic::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Heroic::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Heroic::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Heroic::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Heroic::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Heroic::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Heroic::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Heroic::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Heroic::show() {
    Badges::show();
}

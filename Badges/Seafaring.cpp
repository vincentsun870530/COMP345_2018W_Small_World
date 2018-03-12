//
// Created by vince on 2018/2/14.
//

#include "Seafaring.h"

Seafaring::Seafaring() : Badges() {
    badgesName_= "Seafaring";
    specialPowerDescription_ = "As long as your Seafaring race is active, you may conquer the Seas and the Lake, considering them as 3 empty Regions. You keep these Regions even once you go into Decline, and continue scoring for them for as long as you have tokens there. Only Seafaring races may occupy the Seas and the Lake.";
    tokenAmount_=5;
}

Seafaring::Seafaring(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Seafaring::~Seafaring() {

}

void Seafaring::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Seafaring::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Seafaring::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Seafaring::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Seafaring::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Seafaring::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Seafaring::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Seafaring::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Seafaring::show() {
    Badges::show();
}

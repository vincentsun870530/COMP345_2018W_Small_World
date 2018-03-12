//
// Created by vince on 2018/2/13.
//

#include "Bivouacking.h"

Bivouacking::Bivouacking() : Badges() {
    badgesName_ = "Bivouacking";
    specialPowerDescription_ = "Deploy the 5 Encampment tokens in any of your Region(s), during your Troop Redeployment phase. Each Encampment counts as 1 Race token toward the defense of the Region in which it is placed (thereby protecting a single Race token with an Encampment from the Sorcerer's Racial Power). Multiple Encampments may be placed in the same Region to obtain a higher defense bonus. Each turn you may break camp and settle in any new Region you occupy. Encampments are never lost during an attack on the Region they are in: they are redeployed at the end of the current player's turn. When the Race they were associated with goes into Decline, they disappear.";
    tokenAmount_ = 5;
}

Bivouacking::Bivouacking(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Bivouacking::~Bivouacking() {

}

void Bivouacking::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Bivouacking::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Bivouacking::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Bivouacking::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Bivouacking::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Bivouacking::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Bivouacking::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Bivouacking::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Bivouacking::show() {
    Badges::show();
}

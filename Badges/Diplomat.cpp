//
// Created by vince on 2018/2/14.
//

#include "Diplomat.h"

Diplomat::Diplomat() : Badges() {
    badgesName_ = "Diplomat";
    specialPowerDescription_ = "At the end of your turn, you may select one opponent whose Active race you did not attack this turn as your ally. You are now at peace with him and he cannot attack your active race until your next turn. You may change allies each turn, or stay at peace with the same opponent. Tokens In Decline are not impacted (so Ghouls In Decline are immune to this power and may still attack you).";
    tokenAmount_ = 5;
}

Diplomat::Diplomat(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
        : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

Diplomat::~Diplomat() {

}

void Diplomat::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Diplomat::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Diplomat::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Diplomat::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Diplomat::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Diplomat::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Diplomat::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Diplomat::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Diplomat::show() {
    Badges::show();
}

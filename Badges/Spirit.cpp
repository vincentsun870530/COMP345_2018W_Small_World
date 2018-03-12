//
// Created by vince on 2018/2/14.
//

#include "Spirit.h"

Spirit::Spirit() : Badges() {
    badgesName_="Spirit";
    specialPowerDescription_ = "When the Race tokens associated with your Spirit Special Power go into Decline, they never count toward the limit stated in Entering In Decline (p. 6) regarding having a single In Decline race on the map at any given time. You may thus end up with two different races In Decline on the map at the same time and score for them both.If a third race you control goes into Decline, your Spirits remain on the board, although the other race already In Decline disappears, as normal. In other words, your In Decline Spirits never leave the map (except when taking losses from opponents' conquests), though other races sent In Decline may go away when a new race goes into decline.";
    tokenAmount_ = 5;
}

Spirit::Spirit(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_) : Badges(
        badgesName_, specialPowerDescription_, tokenAmount_) {

}

Spirit::~Spirit() {

}

void Spirit::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Spirit::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Spirit::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Spirit::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Spirit::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Spirit::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Spirit::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Spirit::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Spirit::show() {
    Badges::show();
}

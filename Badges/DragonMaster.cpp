//
// Created by vince on 2018/2/14.
//

#include "DragonMaster.h"

DragonMaster::DragonMaster() : Badges() {
    badgesName_ ="DragonMaster";
    specialPowerDescription_ = "Once per turn, you may conquer a Region using a single Race token, regardless of the number of enemy tokens defending it. Once conquered, place your Dragon there. The Region is now immune to enemy conquests as well as to their racial and special powers until your Dragon moves. During each new turn, you may move your Dragon to a different Region you wish to conquer. Your Dragon disappears when you go into Decline; remove it from the board and place it back in the storage tray at that time.";
    tokenAmount_ = 5;
}

DragonMaster::DragonMaster(const std::string &badgesName_, const std::string &specialPowerDescription_,
                           int tokenAmount_) : Badges(badgesName_, specialPowerDescription_, tokenAmount_) {

}

DragonMaster::~DragonMaster() {

}

void DragonMaster::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void DragonMaster::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void DragonMaster::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int DragonMaster::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string DragonMaster::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string DragonMaster::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int DragonMaster::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void DragonMaster::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void DragonMaster::show() {
    Badges::show();
}

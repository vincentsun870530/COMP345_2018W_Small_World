//
// Created by vince on 2018/2/14.
//

#include "Forest.h"

Forest::Forest() : Badges() {
    badgesName_ ="Forest";
    specialPowerDescription_ = "Collect 1 bonus Victory coin for each Forest Region you occupy at turn's end.";
    tokenAmount_ =4;

}

Forest::Forest(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_) : Badges(
        badgesName_, specialPowerDescription_, tokenAmount_) {

}

Forest::~Forest() {

}

void Forest::setBadgesName_(const std::string &badgesName) {
    Badges::setBadgesName_(badgesName);
}

void Forest::setSpecialPowerDescription_(const std::string &specialPowerDescription) {
    Badges::setSpecialPowerDescription_(specialPowerDescription);
}

void Forest::setTokenAmount_(int tokenAmount) {
    Badges::setTokenAmount_(tokenAmount);
}

int Forest::getTokenAmount_() {
    return Badges::getTokenAmount_();
}

const std::string Forest::getbadgesName() {
    return Badges::getbadgesName();
}

const std::string Forest::getSpecialPowerName() {
    return Badges::getSpecialPowerName();
}

int Forest::startSuperPowerForVictoryCoin(int victoryCoin) {
    return Badges::startSuperPowerForVictoryCoin(victoryCoin);
}

void Forest::startSuperPowerForToken(int tempToken) {
    Badges::startSuperPowerForToken(tempToken);
}

void Forest::show() {
    Badges::show();
}

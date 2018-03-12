//
// Created by vince on 2018/2/10.
//

#include "Skeletons.h"

Skeletons::Skeletons() : RaceBanner() {
    raceName_ = "Skeletons";
    racePowerDescription_ = "During your Troop Redeployment, you receive 1 new Skeleton token for every 2 non-empty Regions you conquered this turns. It's automatically added to the troops you redeploy at the end of your turn.";
    tokenAmount_ = 6;
}

Skeletons::~Skeletons() {

}

Skeletons::Skeletons(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_)
        : RaceBanner(raceName_, racePowerDescription_, tokenAmount_) {

}

void Skeletons::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void Skeletons::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void Skeletons::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int Skeletons::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string Skeletons::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string Skeletons::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int Skeletons::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void Skeletons::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void Skeletons::show() {
    RaceBanner::show();
}

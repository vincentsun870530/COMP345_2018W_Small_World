//
// Created by vince on 2018/2/10.
//

#include "LostTribes.h"

LostTribes::LostTribes() : RaceBanner() {
    setRaceName_("LostTribes");
    setSpecialPowerDescription_(
            "The Lost Tribes are remnants of long-forgotten civilizations that have fallen into decline but still populate some Regions at game start");
}

LostTribes::~LostTribes() {

}

void LostTribes::setRaceName_(const std::string &raceName) {
    RaceBanner::setRaceName_(raceName);
}

void LostTribes::setSpecialPowerDescription_(const std::string &racePowerDescription) {
    RaceBanner::setSpecialPowerDescription_(racePowerDescription);
}

void LostTribes::setTokenAmount_(int tokenAmount_) {
    RaceBanner::setTokenAmount_(tokenAmount_);
}

int LostTribes::getTokenAmount_() {
    return RaceBanner::getTokenAmount_();
}

const std::string LostTribes::getRaceName() {
    return RaceBanner::getRaceName();
}

const std::string LostTribes::getRacePowerName() {
    return RaceBanner::getRacePowerName();
}

int LostTribes::startRacePowerForVictoryCoin(int victoryCoin) {
    return RaceBanner::startRacePowerForVictoryCoin(victoryCoin);
}

void LostTribes::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(tempToken);
}

void LostTribes::show() {
    RaceBanner::show();
}

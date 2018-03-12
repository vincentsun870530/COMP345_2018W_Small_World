//
// Created by vince on 2018/2/9.
//

#include "Amazons.h"

Amazons::Amazons() {
    setRaceName_("Amazons");
    setSpecialPowerDescription_(
            "Four additional Amazon tokens may be used for conquest only, not for defense. So you start your initial turn with 6 + 4 = Amazon tokens(plus any additional ones you may get from the Special Power associated with your Amazons, depending on your combo.");
    setTokenAmount_(6);
};

Amazons::~Amazons() {


};

int Amazons::startRacePowerForVictoryCoin(int VictoryCoin) {

    return (VictoryCoin);

}

void Amazons::startRacePowerForToken(int tempToken) {

    RaceBanner::startRacePowerForToken(4);

}

void Amazons::show() {
    RaceBanner::show();
};
//
// Created by vince on 2018/2/9.
//

#include "Dwarves.h"
Dwarves::Dwarves() {
    setRaceName_("Dwarves");
    setSpecialPowerDescription_("Each Mine Region your Dwarves occuupy is worth 1 bonus Victiory coin, at the end of your turn. This Power is kept even when Dwarves are In Decline.");
    setTokenAmount_(3);
};


Dwarves::~Dwarves() {


};

int Dwarves::startRacePowerForVictoryCoin(int VictoryCoin) {

    return (VictoryCoin + 1);

}

void Dwarves::startRacePowerForToken(int tempToken) {
    RaceBanner::startRacePowerForToken(0);
}

void Dwarves::show() {
    RaceBanner::show();
}
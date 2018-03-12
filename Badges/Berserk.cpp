//
// Created by vince on 2018/2/9.
//

#include "Berserk.h"

Berserk::Berserk() {

    setBadgesName_("Berserk");
    setSpecialPowerDescription_(
            "You may use the Reinforcement die before each of your conquests, rather than just the last one. Roll the die first; select the Region you wish to conquer; The number of Race tokens required to conquer this region will automatically adjust, based on your die roll. If you do not have enough tokens left, this is your final conquest attempt for the turn. As usual, a minimum of 1 token is still required to attempt any conquest.");
    setTokenAmount_(4);
};


Berserk::~Berserk() {


};

int Berserk::startSuperPowerForVictoryCoin(int VictoryCoin) {

    return (VictoryCoin);

}

void Berserk::startSuperPowerForToken(int tempToken) {

    Badges::startSuperPowerForToken(tempToken);

}

void Berserk::show() {
    Badges::show();
};

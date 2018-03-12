//
// Created by vince on 2018/2/9.
//

#ifndef SMALLWORLD_AMAZONS_H
#define SMALLWORLD_AMAZONS_H


#include "RaceBanner.h"

class Amazons : public RaceBanner {
public:

    Amazons();

    ~Amazons();

    int startRacePowerForVictoryCoin(int victoryCoin);

    void startRacePowerForToken(int tempToken);

    void show();
};


#endif //SMALLWORLD_AMAZONS_H

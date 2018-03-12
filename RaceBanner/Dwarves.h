//
// Created by vince on 2018/2/9.
//

#ifndef SMALLWORLD_DWARVES_H
#define SMALLWORLD_DWARVES_H


#include "RaceBanner.h"

class Dwarves : public RaceBanner{
public:
    Dwarves();
    ~Dwarves();
    int  startRacePowerForVictoryCoin(int victoryCoin);
    void  startRacePowerForToken(int tempToken);
    void show();
};


#endif //SMALLWORLD_DWARVES_H

//
// Created by vince on 2018/2/9.
//

#ifndef SMALLWORLD_BERSERK_H
#define SMALLWORLD_BERSERK_H


#include "Badges.h"

class Berserk : public Badges{
public:
    Berserk();
    ~Berserk();
    int  startSuperPowerForVictoryCoin(int victoryCoin);
    void  startSuperPowerForToken(int tempToken);
    void show();

};


#endif //SMALLWORLD_BERSERK_H

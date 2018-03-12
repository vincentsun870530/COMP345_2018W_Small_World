//
// Created by vince on 2018/2/9.
//

#ifndef SMALLWORLD_ALCHEMIST_H
#define SMALLWORLD_ALCHEMIST_H
#include "Badges.h"

class Alchemist : public Badges {
public:
    Alchemist();
    ~Alchemist();
    int  startSuperPowerForVictoryCoin(int victoryCoin);
    void  startSuperPowerForToken(int temToken);
    void show();

};


#endif //SMALLWORLD_ALCHEMIST_H

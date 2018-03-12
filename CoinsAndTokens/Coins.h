//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_COINSANDTOKENS_H
#define SMALLWORLD_COINSANDTOKENS_H

#include <iostream>

class Coins {

public:
    Coins();

    ~Coins();

    Coins(int initialCoins);

    int getCoinsAmount() const;

    void setInitialCoins(int initialCoins);

    void showCoins();

private:
    int coins;

};


#endif //SMALLWORLD_COINSANDTOKENS_H

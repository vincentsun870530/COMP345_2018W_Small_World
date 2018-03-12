//
// Created by vince on 2018/2/10.
//

#include "Coins.h"

int Coins::getCoinsAmount() const {
    return coins;
}

void Coins::setInitialCoins(int initialCoins) {

    Coins::coins = initialCoins;
}

Coins::Coins() {}

Coins::~Coins() {

}

Coins::Coins(int initialCoins) : coins(initialCoins) {}

void Coins::showCoins() {

    std::cout << "Total Coin is " << getCoinsAmount() << std::endl;

}

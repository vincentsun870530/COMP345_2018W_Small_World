//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_HEROES_H
#define SMALLWORLD_HEROES_H


#include "GamePiece.h"

class Heroes  : public GamePiece{
public:
    Heroes();

    Heroes(const std::string &pieceName, int totalAmount);

    ~Heroes() override;

    const std::string getName() override;

    int getTokenCost() override;

    void show() override;

    void setTotalAmount_(int totalAmount_) override;
};


#endif //SMALLWORLD_HEROES_H

//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_LAIRFROMTROLL_H
#define SMALLWORLD_LAIRFROMTROLL_H


#include "GamePiece.h"

class LairFromTroll  : public GamePiece{
public:
    LairFromTroll();

    LairFromTroll(const std::string &pieceName, int totalAmount);

    ~LairFromTroll() override;

    const std::string getName() override;

    int getTokenCost() override;

    void show() override;
};


#endif //SMALLWORLD_LAIRFROMTROLL_H

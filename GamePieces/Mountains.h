//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_MOUNTAINS_H
#define SMALLWORLD_MOUNTAINS_H


#include "GamePiece.h"

class Mountains : public GamePiece{
public:
    Mountains();

    Mountains(const std::string &pieceName, int totalAmount);

    ~Mountains() override;

    const std::string getName() override;

    int getTokenCost() override;

    void show() override;

    void setTotalAmount_(int totalAmount_) override;
};


#endif //SMALLWORLD_MOUNTAINS_H

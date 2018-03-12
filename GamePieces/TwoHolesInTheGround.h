//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_TWOHOLESINTHEGROUND_H
#define SMALLWORLD_TWOHOLESINTHEGROUND_H


#include "GamePiece.h"

class TwoHolesInTheGround : public GamePiece{

public:
    TwoHolesInTheGround();

    TwoHolesInTheGround(const std::string &pieceName, int totalAmount);

    ~TwoHolesInTheGround() override;

    const std::string getName() override;

    int getTokenCost() override;

    void show() override;

    void setTotalAmount_(int totalAmount_) override;


};


#endif //SMALLWORLD_TWOHOLESINTHEGROUND_H

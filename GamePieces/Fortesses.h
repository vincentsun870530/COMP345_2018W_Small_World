//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_FORTESSES_H
#define SMALLWORLD_FORTESSES_H


#include "GamePiece.h"

class Fortesses : public GamePiece {
public:
    Fortesses();

    Fortesses(const std::string &pieceName, int totalAmount);

    ~Fortesses() override;

    const std::string getName() override;

    int getTokenCost() override;

    void show() override;

    void setTotalAmount_(int totalAmount_) override;
};


#endif //SMALLWORLD_FORTESSES_H

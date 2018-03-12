//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_ENCAMPMENTS_H
#define SMALLWORLD_ENCAMPMENTS_H


#include "GamePiece.h"

class Encampments : public GamePiece{
public:
    Encampments();

    Encampments(const std::string &pieceName, int totalAmount);

    ~Encampments() override;

    const std::string getName() override;

    int getTokenCost() override;

    void show() override;

    void setTotalAmount_(int totalAmount_) override;
};


#endif //SMALLWORLD_ENCAMPMENTS_H

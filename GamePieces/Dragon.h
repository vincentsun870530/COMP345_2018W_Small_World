//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_DRAGON_H
#define SMALLWORLD_DRAGON_H


#include "GamePiece.h"

class Dragon : public GamePiece {
public:
    Dragon();

    Dragon(const std::string &pieceName, int totalAmount);

    ~Dragon() override;

    const std::string getName() override;

    int getTokenCost() override;

    void show() override;

   void setTotalAmount_(int totalAmount_) override;

};


#endif //SMALLWORLD_DRAGON_H

//
// Created by vince on 2018/2/10.
//

#include "Dragon.h"

Dragon::Dragon() : GamePiece() {
    pieceName_ = "Dragon";
	totalAmount_ = 1;
}

Dragon::Dragon(const std::string &pieceName, int totalAmount) : GamePiece(pieceName, totalAmount) {

}

Dragon::~Dragon() {

}

const std::string Dragon::getName() {
    return GamePiece::getName();
}

int Dragon::getTokenCost() {
    return GamePiece::getTokenCost();
}

void Dragon::show() {
    GamePiece::show();
}

void Dragon::setTotalAmount_(int totalAmount_) {
    GamePiece::setTotalAmount_(totalAmount_);
}
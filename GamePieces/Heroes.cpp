//
// Created by vince on 2018/2/10.
//

#include "Heroes.h"

Heroes::Heroes() : GamePiece() {
    pieceName_ = "Heroes";
	totalAmount_ = 2;
}

Heroes::Heroes(const std::string &pieceName, int totalAmount) : GamePiece(pieceName, totalAmount) {

}

Heroes::~Heroes() {

}

const std::string Heroes::getName() {
    return GamePiece::getName();
}

int Heroes::getTokenCost() {
    return GamePiece::getTokenCost();
}

void Heroes::show() {
    GamePiece::show();
}

void Heroes::setTotalAmount_(int totalAmount_) {
    GamePiece::setTotalAmount_(totalAmount_);
}

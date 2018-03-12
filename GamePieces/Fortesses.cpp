//
// Created by vince on 2018/2/10.
//

#include "Fortesses.h"

Fortesses::Fortesses() : GamePiece() {
    pieceName_ = "Fortesses";
	totalAmount_ = 6;
}

Fortesses::Fortesses(const std::string &pieceName, int totalAmount) : GamePiece(pieceName, totalAmount) {

}

Fortesses::~Fortesses() {

}

const std::string Fortesses::getName() {
    return GamePiece::getName();
}

int Fortesses::getTokenCost() {
    return GamePiece::getTokenCost();
}

void Fortesses::show() {
    GamePiece::show();
}

void Fortesses::setTotalAmount_(int totalAmount_) {
    GamePiece::setTotalAmount_(totalAmount_);
}

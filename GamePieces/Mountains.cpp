//
// Created by vince on 2018/2/10.
//

#include "Mountains.h"

Mountains::Mountains() : GamePiece() {
    pieceName_ = "Mountains";
	totalAmount_ = 9;
}

Mountains::Mountains(const std::string &pieceName, int totalAmount) : GamePiece(pieceName, totalAmount) {

}

Mountains::~Mountains() {

}

const std::string Mountains::getName() {
    return GamePiece::getName();
}

int Mountains::getTokenCost() {
    return GamePiece::getTokenCost();
}

void Mountains::show() {
    GamePiece::show();
}

void Mountains::setTotalAmount_(int totalAmount_) {
    GamePiece::setTotalAmount_(totalAmount_);
}

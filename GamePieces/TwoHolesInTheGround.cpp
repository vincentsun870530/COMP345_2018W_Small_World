//
// Created by vince on 2018/2/10.
//

#include "TwoHolesInTheGround.h"

TwoHolesInTheGround::TwoHolesInTheGround() : GamePiece() {
    pieceName_ = "TwoHolesInTheGround";
	totalAmount_ = 2;
}

TwoHolesInTheGround::TwoHolesInTheGround(const std::string &pieceName, int totalAmount) : GamePiece(pieceName,
                                                                                                    totalAmount) {

}

TwoHolesInTheGround::~TwoHolesInTheGround() {

}

const std::string TwoHolesInTheGround::getName() {
    return GamePiece::getName();
}

int TwoHolesInTheGround::getTokenCost() {
    return GamePiece::getTokenCost();
}

void TwoHolesInTheGround::show() {
    GamePiece::show();
}

void TwoHolesInTheGround::setTotalAmount_(int totalAmount_) {
    GamePiece::setTotalAmount_(totalAmount_);
}

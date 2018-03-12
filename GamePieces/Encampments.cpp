//
// Created by vince on 2018/2/10.
//

#include "Encampments.h"

Encampments::Encampments() : GamePiece() {
    pieceName_ = "Encampments";
	totalAmount_ = 5;
}

Encampments::Encampments(const std::string &pieceName, int totalAmount) : GamePiece(pieceName, totalAmount) {

}

Encampments::~Encampments() {

}

const std::string Encampments::getName() {
    return GamePiece::getName();
}

int Encampments::getTokenCost() {
    return GamePiece::getTokenCost();
}

void Encampments::show() {
    GamePiece::show();
}

void Encampments::setTotalAmount_(int totalAmount_) {
    GamePiece::setTotalAmount_(totalAmount_);
}

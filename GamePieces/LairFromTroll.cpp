//
// Created by vince on 2018/2/10.
//

#include "LairFromTroll.h"

LairFromTroll::LairFromTroll() : GamePiece() {
    pieceName_ = "LairFromTroll";
	totalAmount_ = 10;
}

LairFromTroll::LairFromTroll(const std::string &pieceName, int totalAmount) : GamePiece(pieceName, totalAmount) {

}

LairFromTroll::~LairFromTroll() {

}

const std::string LairFromTroll::getName() {
    return GamePiece::getName();
}

int LairFromTroll::getTokenCost() {
    return GamePiece::getTokenCost();
}

void LairFromTroll::show() {
    GamePiece::show();
}


#include "GamePiece.h"

GamePiece::GamePiece() {
}

GamePiece::GamePiece(const std::string &pieceName, int totalAmount) {
    pieceName_ = pieceName;
    totalAmount_ = totalAmount;
}

GamePiece::~GamePiece() {
}


const std::string GamePiece::getName() {
    return pieceName_;
}

int GamePiece::getTokenCost() {
    return totalAmount_;
}

void GamePiece::show() {

    std::cout << "Piece Name is " << pieceName_ << std::endl;
    std::cout << "Token Amount is " << totalAmount_ << std::endl;

}

void GamePiece::setTotalAmount_(int totalAmount_) {
    GamePiece::totalAmount_ = totalAmount_;
}

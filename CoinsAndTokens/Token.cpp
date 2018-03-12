#include "Token.h"


Token::Token() {
}


Token::~Token() {
}

Token::Token(int initialToken) {

    tokenAmount_ = initialToken;

}

void Token::setTokenAmount_(int tokenAmount_) {
    Token::tokenAmount_ = tokenAmount_;
}

int Token::getTokenAmount() {
    return tokenAmount_;
}

void Token::showTokens() {

    std::cout << "Token amount is " << tokenAmount_ << std::endl;

};

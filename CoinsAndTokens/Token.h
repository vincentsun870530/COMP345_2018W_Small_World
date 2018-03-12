#pragma once

#include <iostream>
#include <string>

class Token {
public:
    Token();

    Token(int initialToken);

    ~Token();

    int getTokenAmount();

    void showTokens();

    void setTokenAmount_(int tokenAmount_);

private:
    int tokenAmount_;
};


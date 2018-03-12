#pragma once
#include <iostream>
#include <string>


class GamePiece
{

public:

	GamePiece(); // default constructor

	GamePiece(const std::string & pieceName, int totalAmount);

    virtual ~GamePiece();

    virtual const std::string getName();

    virtual int getTokenCost();

	virtual void show();

    virtual void setTotalAmount_(int totalAmount_);

protected:
	std::string pieceName_;
	int totalAmount_;
};


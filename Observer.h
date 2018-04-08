#pragma once

class Observer
{
public:
	Observer(){};
	~Observer(){};
	virtual void update() = 0;
	virtual void display() = 0;
};


#pragma once

#include <iostream>  
#include <stdlib.h>  
#include <time.h>  

using namespace std;

class Dice
{
public:
	Dice() { rollingTimes = 0;  r0Times = r1Times = r2Times = r3Times = 0; 
	r0Percentage = r1Percentage = r2Percentage = r3Percentage = 0;};
	~Dice();
	int rollingDice(bool showResult);
	void showPercentage();
private:
	int rollingTimes;
	int r0Times, r1Times, r2Times, r3Times;
	double r0Percentage;
	double r1Percentage;
	double r2Percentage;
	double r3Percentage;
};


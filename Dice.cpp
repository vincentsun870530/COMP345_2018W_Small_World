#include "Dice.h"


Dice::~Dice()
{

}

int Dice::rollingDice(bool showResult = false) {

	int rollNumber;
	int returnNUmber;

	rollingTimes++;

	rollNumber =  rand() % 6 ;
	returnNUmber = (rollNumber / 3) * (rollNumber % 3 + 1);
	
	cout << "you get a rollNumber " << rollNumber << " this time. " << endl;

	if (returnNUmber) {
		if (returnNUmber == 1) {r1Times++, r1Percentage = (double)r1Times / rollingTimes *100 ;}
		else if (returnNUmber == 2) { r2Times++, r2Percentage = (double)r2Times / rollingTimes* 100; }
		else { r3Times++, r3Percentage = (double)r3Times / rollingTimes *100; };
	}
	else { r0Times++, r0Percentage = (double)r0Times / rollingTimes * 100; };

	if (showResult) cout << "you get a " << returnNUmber << " this time. " << endl;
	return returnNUmber;
};

void Dice::showPercentage()
{
	cout << " So far you paly the roll " << rollingTimes << " times " << endl;
	cout << "among the numbers " << "you get 0 " << r0Times << " times " << ", this account for " << r0Percentage << " %!" <<endl;
	cout << "                  " << "you get 1 " << r1Times << " times " << ", this account for " << r1Percentage << " %!" << endl;
	cout << "                  " << "you get 2 " << r2Times << " times " << ", this account for " << r2Percentage << " %!" << endl;
	cout << "                  " << "you get 3 " << r3Times << " times " << ", this account for " << r3Percentage << " %!" << endl;
};


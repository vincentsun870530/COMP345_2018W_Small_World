#include "Badges.h"


Badges::Badges() {
	// std::cout << "Badges Created" << std::endl;
	badgesName_ = "";
	specialPowerDescription_ = "";
	tokenAmount_ = 0;
}

Badges::~Badges() {
	// std::cout << "Badges Deleted" << std::endl;
}

Badges::Badges(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_)
	: badgesName_(badgesName_), specialPowerDescription_(specialPowerDescription_), tokenAmount_(tokenAmount_) {}

void Badges::setBadgesName_(const std::string &badgesName) {

	badgesName_ = badgesName;
}


void Badges::setSpecialPowerDescription_(const std::string &specialPowerDescription) {

	specialPowerDescription_ = specialPowerDescription;

}

void Badges::setTokenAmount_(int tokenAmount) {
	tokenAmount_ = tokenAmount;
}


const std::string Badges::getbadgesName() {

	return badgesName_;
}

const std::string Badges::getSpecialPowerName() {

	return specialPowerDescription_;
}

int Badges::getTokenAmount_() {
	return tokenAmount_;
}

void Badges::show() {
	std::cout << "Badge name is " << getbadgesName() << std::endl;
	std::cout << "SpecialPower Description is " << getSpecialPowerName() << std::endl;
	std::cout << "It has " << getTokenAmount_() << " tokens. " << std::endl;
	std::cout << "============================================" << std::endl;
};

int Badges::startSuperPowerForVictoryCoin(int victoryCoin) {

	return (victoryCoin += 0);

}

void Badges::startSuperPowerForToken(int tempToken) {

	tokenAmount_ = tokenAmount_ + tempToken;

}
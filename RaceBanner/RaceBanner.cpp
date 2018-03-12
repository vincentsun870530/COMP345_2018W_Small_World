#include "RaceBanner.h"

RaceBanner::RaceBanner() {
	//std::cout << "RaceBanner Created" << std::endl;
	raceName_ = "";
	racePowerDescription_ = "";
	tokenAmount_ = 0;
}

RaceBanner::RaceBanner(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_)
	: raceName_(raceName_), racePowerDescription_(racePowerDescription_), tokenAmount_(tokenAmount_) {}

RaceBanner::~RaceBanner() {
	//std::cout << "RaceBanner Deleted" << std::endl;
}

void RaceBanner::setRaceName_(const std::string &raceName) {
	raceName_ = raceName;
}

void RaceBanner::setSpecialPowerDescription_(const std::string &racePowerDescription) {
	racePowerDescription_ = racePowerDescription;
}

void RaceBanner::setTokenAmount_(int tokenAmount_) {
	RaceBanner::tokenAmount_ = tokenAmount_;
}

int RaceBanner::getTokenAmount_() {
	return tokenAmount_;
}

const std::string RaceBanner::getRaceName() {
	return raceName_;

}

const std::string RaceBanner::getRacePowerName() {
	return racePowerDescription_;
}

int RaceBanner::startRacePowerForVictoryCoin(int victoryCoin) {

	return victoryCoin;
}

void RaceBanner::startRacePowerForToken(int tempToken) {
	tokenAmount_ = tokenAmount_ + tempToken;
}

void RaceBanner::show() {
	std::cout << "Race name is " << getRaceName() << std::endl;
	std::cout << "Race power description is " << getRacePowerName() << std::endl;
	std::cout << "It has " << getTokenAmount_() << " tokens " << std::endl;
	std::cout << "============================================" << std::endl;
}





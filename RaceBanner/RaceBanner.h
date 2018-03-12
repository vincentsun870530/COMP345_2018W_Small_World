#pragma once

#include <iostream>
#include <string>
#include "../CoinsAndTokens/Token.h"

class Players;
class Region;

class RaceBanner {
public:
	RaceBanner();

	virtual ~RaceBanner();

	RaceBanner(const std::string &raceName_, const std::string &racePowerDescription_, int tokenAmount_);

	virtual void setRaceName_(const std::string &raceName);

	virtual void setSpecialPowerDescription_(const std::string &racePowerDescription);

	virtual void setTokenAmount_(int tokenAmount_);

	virtual int getTokenAmount_();

	virtual const std::string getRaceName();

	virtual const std::string getRacePowerName();

	virtual int startRacePowerForVictoryCoin(int victoryCoin);

	virtual void startRacePowerForToken(int tempToken);

	virtual void show();

	int get_id_race() const
	{
		return ID_Race;
	}

	void set_id_race(const int id_race)
	{
		ID_Race = id_race;
	}

	bool is_available() const
	{
		return isAvailable;
	}

	void set_is_available(const bool is_available)
	{
		isAvailable = is_available;
	}

	Players * get_point_player() const
	{
		return PointPlayer;
	}

	void set_point_player(Players* const point_player)
	{
		PointPlayer = point_player;
	}

	//Amazons
	virtual void afterAttackRetrealt() {};


	//Elves
	virtual void specialWithdraws(int ID_Region) {};

	//Ghouls
	virtual void readyDeclinedTroop() {};
	virtual void beforeAttackspecialAttack() {};
	virtual void additionalDeploy() {}; // alread integrated in 

	//Giants Tritons
	virtual int conquerForceDemandCount(int ID_Region) { return 0; };

	//Halflings
	virtual bool regionAttackAprove(int ID_Region) { return true; }; //Tritons
	virtual void specialDeploy() {}; //Skeletons

	//Humans orcs Wizards Dwarves
	virtual int specialRegionBonusCount() { return 0; };

	//Sorcerers
	virtual void alternativeExchangeAttack(int ID_Region) { }; //"need check availability"

	//Trolls
	virtual void specialDeclined() {}; 





protected:
	int ID_Race = -1;
	std::string raceName_;
	std::string racePowerDescription_;
	int tokenAmount_;
	bool isAvailable = true;
	Players * PointPlayer = nullptr;
};



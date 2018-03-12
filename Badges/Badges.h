#pragma once

#include <iostream>
#include <string>
#include "../RaceBanner/RaceBanner.h"

class Players;

class Badges {
public:
	Badges();

	Badges(const std::string &badgesName_, const std::string &specialPowerDescription_, int tokenAmount_);

	virtual ~Badges();

	virtual void setBadgesName_(const std::string &badgesName);

	virtual void setSpecialPowerDescription_(const std::string &specialPowerDescription);

	virtual void setTokenAmount_(int tokenAmount);

	virtual int getTokenAmount_();

	virtual const std::string getbadgesName();

	virtual const std::string getSpecialPowerName();

	virtual int startSuperPowerForVictoryCoin(int victoryCoin);

	virtual void startSuperPowerForToken(int tempToken);

	virtual void show();

	int get_id_badges() const
	{
		return ID_badges;
	}

	void set_id_badges(const int id_badges)
	{
		ID_badges = id_badges;
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

	//Alchemist Merchant  Hill  Forest  Pillaging  Swamp  Wealthy
	virtual int specialRegionBounsCountTurnEnd() { return 0; };

	//Berserk Commando Fortified Mounted  Seafaring  Underworld
	virtual int conquerForceDemandCount(int ID_Region) { return 0; };

	//Bivouacking DragonMaster Fortified Heroic
	virtual void specialDeployAfterAttack() {};

	//Diplomat DragonMaster Flying Heroic Seafaring  
	virtual bool regionAttackAprove(int ID_Region) { return true; }; 

	//DragonMaster
	virtual void alternativeSpecialAttack(int ID_Region) {}; //"need check availability"

	//Stout
	virtual void declineIntermidiatelyAfterAttack() {};





protected:
	int ID_badges = -1;
	std::string badgesName_;
	std::string specialPowerDescription_;
	int tokenAmount_;
	bool isAvailable = true;
	Players * PointPlayer = nullptr;
};


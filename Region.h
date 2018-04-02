#pragma once

namespace boost {
	namespace serialization {
		class access;
	}
}

#include <vector>
#include <string>
#include <stdbool.h>
#include "GamePieces/GamePiece.h"

class Observer;

class Region
{
public:
	Region();
	~Region();
	//void setRegionID(int n);
	//int getRegionID() { return getRegionID(); };
	//int getOwner() { return getOwner(); };
	void printRegion();

	int get_region_id() const
	{
		return regionID;
	}

	int get_owner() const
	{
		return owner;
	}

	int get_id_cu_race() const
	{
		return ID_CuRace;
	}

	int get_id_de_race() const
	{
		return ID_DeRace;
	}

	int get_solider_current_race() const
	{
		return soliderCurrentRace;
	}

	int get_solider_declined_race() const
	{
		return soliderDeclinedRace;
	}

	std::string get_region_char() const
	{
		return regionChar;
	}

	std::string get_cu_race_name() const
	{
		return cuRaceName;
	}

	std::string get_de_race_name() const
	{
		return deRaceName;
	}

	int get_encampments_count() const
	{
		return encampmentsCount;
	}

	int get_troll_lairs_count() const
	{
		return trollLairsCount;
	}

	int get_fortresses_count() const
	{
		return fortressesCount;
	}

	int get_holes_in_the_ground_count() const
	{
		return holes_in_the_GroundCount;
	}

	int get_num_removable_game_pieces() const
	{
		return numRemovableGamePieces;
	}

	int get_heroes_count() const
	{
		return heroesCount;
	}

	int get_dragon_count() const
	{
		return dragonCount;
	}

	int get_mountain_count() const
	{
		return mountainCount;
	}

	int get_adjacent_mountain_count() const
	{
		return adjacentMountainCount;
	}

	int get_farmland_count() const
	{
		return farmlandCount;
	}

	int get_empty_region_count() const
	{
		return emptyRegionCount;
	}

	int get_coastal_region_count() const
	{
		return coastalRegionCount;
	}

	int get_magic_region_count() const
	{
		return magicRegionCount;
	}

	int get_mine_region_count() const
	{
		return mineRegionCount;
	}

	int get_is_at_boundary_of_map() const
	{
		return isAtBoundaryOfMap;
	}

	int get_forest_region_count() const
	{
		return forestRegionCount;
	}

	int get_cavern_region_count() const
	{
		return cavernRegionCount;
	}

	int get_swamp_region_count() const
	{
		return swampRegionCount;
	}

	void set_region_id(int region_id)
	{
		regionID = region_id;
	}

	void set_owner(int owner);

	void set_id_cu_race(int id_cu_race)
	{
		ID_CuRace = id_cu_race;
	}

	void set_id_de_race(int id_de_race)
	{
		ID_DeRace = id_de_race;
	}

	void set_solider_current_race(int solider_current_race)
	{
		soliderCurrentRace = solider_current_race;
	}

	void set_solider_declined_race(int solider_declined_race)
	{
		soliderDeclinedRace = solider_declined_race;
	}

	void set_region_char(const std::string& region_char)
	{
		regionChar = region_char;
	}

	void set_cu_race_name(const std::string& cu_race_name)
	{
		cuRaceName = cu_race_name;
	}

	void set_de_race_name(const std::string& de_race_name)
	{
		deRaceName = de_race_name;
	}

	void set_encampments_count(int encampments_count)
	{
		encampmentsCount = encampments_count;
	}

	void set_troll_lairs_count(int troll_lairs_count)
	{
		trollLairsCount = troll_lairs_count;
	}

	void set_fortresses_count(int fortresses_count)
	{
		fortressesCount = fortresses_count;
	}

	void set_holes_in_the_ground_count(int holes_in_the_ground_count)
	{
		holes_in_the_GroundCount = holes_in_the_ground_count;
	}

	void set_num_removable_game_pieces(int num_removable_game_pieces)
	{
		numRemovableGamePieces = num_removable_game_pieces;
	}

	void set_heroes_count(int heroes_count)
	{
		heroesCount = heroes_count;
	}

	void set_dragon_count(int dragon_count)
	{
		dragonCount = dragon_count;
	}

	void set_mountain_count(int mountain_count)
	{
		mountainCount = mountain_count;
	}

	void set_adjacent_mountain_count(int adjacent_mountain_count)
	{
		adjacentMountainCount = adjacent_mountain_count;
	}

	void set_farmland_count(int farmland_count)
	{
		farmlandCount = farmland_count;
	}

	void set_empty_region_count(int empty_region_count)
	{
		emptyRegionCount = empty_region_count;
	}

	void set_coastal_region_count(int coastal_region_count)
	{
		coastalRegionCount = coastal_region_count;
	}

	void set_magic_region_count(int magic_region_count)
	{
		magicRegionCount = magic_region_count;
	}

	void set_mine_region_count(int mine_region_count)
	{
		mineRegionCount = mine_region_count;
	}

	void set_is_at_boundary_of_map(int is_at_boundary_of_map)
	{
		isAtBoundaryOfMap = is_at_boundary_of_map;
	}

	void set_forest_region_count(int forest_region_count)
	{
		forestRegionCount = forest_region_count;
	}

	void set_cavern_region_count(int cavern_region_count)
	{
		cavernRegionCount = cavern_region_count;
	}

	void set_swamp_region_count(int swamp_region_count)
	{
		swampRegionCount = swamp_region_count;
	}

	int get_lost_tribe_count() const
	{
		return lostTribeCount;
	}

	void set_lost_tribe_count(const int lost_tribe_count)
	{
		lostTribeCount = lost_tribe_count;
	}

	int get_former_owner() const
	{
		return formerOwner;
	}

	void set_former_owner(const int former_owner)
	{
		formerOwner = former_owner;
	}

	void attach(Observer * inputObserver);
	void detach(Observer * inputObserver);
	void notify();

private:

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & regionID;
		ar & owner;
		ar & formerOwner;
		ar & ID_CuRace;
		ar & ID_DeRace;
		ar & soliderCurrentRace;
		ar & soliderDeclinedRace;
		ar & regionChar;
		ar & cuRaceName;
		ar & deRaceName;
		ar & encampmentsCount;
		ar & trollLairsCount;
		ar & fortressesCount;
		ar & holes_in_the_GroundCount;
		ar & numRemovableGamePieces;
		ar & heroesCount;
		ar & dragonCount;
		ar & mountainCount;
		ar & adjacentMountainCount;
		ar & farmlandCount;
		ar & emptyRegionCount;
		ar & coastalRegionCount;
		ar & magicRegionCount;
		ar & mineRegionCount;
		ar & isAtBoundaryOfMap;
		ar & forestRegionCount;
		ar & cavernRegionCount;
		ar & swampRegionCount;
		ar & lostTribeCount;
	}


	int  regionID = -1;
	int  owner = -1;
	int  formerOwner = -1;
	int  ID_CuRace = -1;
	int  ID_DeRace = -1;
	int  soliderCurrentRace = 0;
	int  soliderDeclinedRace = 0;
	std::string regionChar = "";
	std::string cuRaceName = "";
	std::string deRaceName = "";
	int encampmentsCount = 0;
	int trollLairsCount = 0;
	int fortressesCount = 0;
	int holes_in_the_GroundCount = 0;
	int numRemovableGamePieces = 0;
	int heroesCount = 0;
	int dragonCount = 0;
	int mountainCount = 0;
	int adjacentMountainCount = 0;
	int farmlandCount = 0;
	int emptyRegionCount = 1;
	int coastalRegionCount = 0;
	int magicRegionCount = 0;
	int mineRegionCount = 0;
	int isAtBoundaryOfMap = 0;
	int forestRegionCount = 0;
	int cavernRegionCount = 0;
	int swampRegionCount = 0;
	int lostTribeCount = 0;

	std::vector<Observer *> playerShareObserver;

};


//
// Created by vince on 2018/2/10.
//

#ifndef SMALLWORLD_PLAYERS_H
#define SMALLWORLD_PLAYERS_H

#include <iostream>
#include "DeckCard.h"
#include "CoinsAndTokens/Coins.h"
#include "Region.h"
#include "Dice.h"
#include "global_variables_clarification.h"
#include "Subject.h"

class RaceBanner;
class Badges;


void showTroopStatusAfterDeploy(vector<int> & inputControlList);
void showPlayersAtTurnEnd();
void printRegionList(vector<int> & inputVector);


class Players : public Subject {

private:
	DeckCard currentdeckCard;
	Coins coins;
	Token token;
	Dice dice;
	vector <Region>regionList;
	DeckCard declineddeckCard;

	int ID_player = -1;
	int coin_1 = 0, coin_3 = 0, coin_5 = 0, coin_10 = 0;
	string phaser = "sleeping";

	vector <int> controlledRegionList;
	vector<int > adjacentRegionList;
	vector<int > turnRegionConquerList;

	RaceBanner * currentRace = nullptr;
	RaceBanner * DeclinedRace = nullptr;
	Badges * currentPower = nullptr;

	int inHandSoliderCurrentRace = 0;
	int inHandSoliderDeclinedRace = 0;
	int inHandTrollLairs = 0;
	int inHandFortresses = 0;
	int inHandEncampments = 0;
	int inHandHole_in_the_ground = 0;
	int inHandhero = 0;
	int inHandDragon = 0;

	bool alreadyCountedBouns = false;

	int playerTotalCoins = 0;

	int returnCurrentRaceTroop(int ID_Region);

public:
	
	vector<int> get_controlled_region_list() { return controlledRegionList; };
	vector<int> get_turn_region_conquer_list() { return turnRegionConquerList; };
	void addTurnRegionConquerList(int ID_region);
	void removeTurnRegionConquerList(int ID_region);
	void clearTurnRegionConquerList(int ID_region) { turnRegionConquerList.clear(); }
	void addControlledRegionID(int ID_region);
	void removeControlledRegionID(int ID_region);
	void updateAdjacentRegionID();

	bool containRegionID(vector<int> * const  regionList, int ID_Region);


	int get_id_player() const
	{
		return ID_player;
	}

	void set_id_player(const int id_player)
	{
		ID_player = id_player;
	}


	const string& get_phaser() const;
	void set_phaser(const string& phaser);
	Players();

	const Dice &getDice() const;

	void setDice(const Dice &dice);

	const vector<Region> &getRegionList() const;

	void setRegionList(const vector<Region> &regionList);

	virtual ~Players();

	const DeckCard &getDeckCard() const;

	void pick_race(const DeckCard &deckCard, int number);

	const Coins &getCoins() const;

	void scores(const Coins &coins);

	const Token &getToken() const;

	void setToken(const Token &token);

	void show();

	void conquers(Region a);

	void conquers(int ID_Region);// added

	void conquerSomeRegions(); //added

	vector<int>  getFirstTimeAvailableAttackRegion();

	vector<int> getAvailableAttackRegion();

	void showAvailableAttackRegion(vector<int> &);
	int getFirstTimeAttackRegionFromUser();
	int getAttackRegionFromUser();

	void firstTurnAttack(); //added
	void followingTurnAttack(); //added
	bool attack(int ID_Region);
	void clearFormerDeclinedRaceSolider();
	//added
	void Decline(); //added
	void abandonAreas(); //added
	void BonusCount(); //added

	void exchangeCoin();//added

	bool isAttckableRegion(int ID_Region); //added
	int normalConquerForceDemandCount(int ID_Region); //added
	void loseAndWithdraws(int ID_Region) ;// added
	void normalAttack(int ID_Region, int solider_needed) ;// added
	void normalDeploy() ;// added
	int normalBonusCount() ;// added

	void readyTroop(); //added
	void add_coin_1();
	void reduce_coin_1();

	void scoringVictoryCoins();

	

	int get_coin_1() const// added
	{
		return coin_1;
	}

	void set_coin_1(const int coin_1)// added
	{
		this->coin_1 = coin_1;
	}

	int get_coin_3() const// added
	{
		return coin_3;
	}

	void set_coin_3(const int coin_3)// added
	{
		this->coin_3 = coin_3;
	}

	int get_coin_5() const// added
	{
		return coin_5;
	}

	void set_coin_5(const int coin_5)// added
	{
		this->coin_5 = coin_5;
	}

	int get_coin_10() const// added
	{
		return coin_10;
	}

	void set_coin_10(const int coin_10)// added
	{
		this->coin_10 = coin_10;
	}

	void printCoins() const;// added

	RaceBanner* get_current_race() const; // added

	void set_current_race(RaceBanner* const current_race);// added

	Badges* get_current_power() const;// added

	void set_current_power(Badges* const current_power);// added

	void pick_race(int i); //overloaded

	void reduceCoinForRaceSelection(int ID_RaceOrBadge); //added

	int raceSelectCoinReduction(int ID_RaceOrBadge); //added

	void pick_race();// added

		RaceBanner * get_declined_race() const
		{
			return DeclinedRace;
		}

		void set_declined_race(RaceBanner* const declined_race)
		{
			DeclinedRace = declined_race;
		}

		int get_in_hand_solider_current_race() const
		{
			return inHandSoliderCurrentRace;
		}

		void set_in_hand_solider_current_race(const int in_hand_solider_current_race)
		{
			inHandSoliderCurrentRace = in_hand_solider_current_race;
		}

		int get_in_hand_solider_declined_race() const
		{
			return inHandSoliderDeclinedRace;
		}

		void set_in_hand_solider_declined_race(const int in_hand_solider_declined_race)
		{
			inHandSoliderDeclinedRace = in_hand_solider_declined_race;
		}

		int get_in_hand_troll_lairs() const
		{
			return inHandTrollLairs;
		}

		void set_in_hand_troll_lairs(const int in_hand_troll_lairs)
		{
			inHandTrollLairs = in_hand_troll_lairs;
		}

		int get_in_hand_fortresses() const
		{
			return inHandFortresses;
		}

		void set_in_hand_fortresses(const int in_hand_fortresses)
		{
			inHandFortresses = in_hand_fortresses;
		}

		int get_in_hand_encampments() const
		{
			return inHandEncampments;
		}

		void set_in_hand_encampments(const int in_hand_encampments)
		{
			inHandEncampments = in_hand_encampments;
		}

		int get_in_hand_hole_in_the_ground() const
		{
			return inHandHole_in_the_ground;
		}

		void set_in_hand_hole_in_the_ground(const int in_hand_hole_in_the_ground)
		{
			inHandHole_in_the_ground = in_hand_hole_in_the_ground;
		}

		int get_in_handhero() const
		{
			return inHandhero;
		}

		void set_in_handhero(const int in_handhero)
		{
			inHandhero = in_handhero;
		}

		int get_in_hand_dragon() const
		{
			return inHandDragon;
		}

		void set_in_hand_dragon(const int in_hand_dragon)
		{
			inHandDragon = in_hand_dragon;
		}

		bool get_already_counted_bouns() const
		{
			return alreadyCountedBouns;
		}

		void set_already_counted_bouns(const bool already_counted_bouns)
		{
			alreadyCountedBouns = already_counted_bouns;
		}

		int  get_player_total_coins() const
		{
			return playerTotalCoins;
		}

		void set_player_total_coins(const int player_total_coins)
		{
			playerTotalCoins = player_total_coins;
		}
		
};


#endif //SMALLWORLD_PLAYERS_H

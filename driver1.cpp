#include "Map.h"
#include "Region.h"
#include "Dice.h"
#include "MapLoader.h"
#include <iostream>
#include <stdbool.h>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/graph/adj_list_serialize.hpp>
#include "Region.h"
#include <iostream>
#include <string>
#include "GamePieces/GamePiece.h"
#include <vector>
#include "DeckCard.h"
#include "Badges/Alchemist.h"
#include "Badges/Berserk.h"
#include "RaceBanner/Amazons.h"
#include "RaceBanner/Dwarves.h"
#include "CoinsAndTokens/Coins.h"
#include "RaceBanner/LostTribes.h"
#include "GamePieces/Mountains.h"
#include "GamePieces/Dragon.h"
#include "GamePieces/Fortesses.h"
#include "GamePieces/LairFromTroll.h"
#include "GamePieces/Heroes.h"
#include "GamePieces/Encampments.h"
#include "GamePieces/TwoHolesInTheGround.h"
#include "Players.h"
#include "RaceBanner/Elves.h"
#include "RaceBanner/Ghouls.h"
#include "RaceBanner/Giants.h"
#include "RaceBanner/Halflings.h"
#include "RaceBanner/Humans.h"
#include "RaceBanner/Orcs.h"
#include "RaceBanner/Ratmen.h"
#include "RaceBanner/Skeletons.h"
#include "RaceBanner/Sorceres.h"
#include "RaceBanner/Tritons.h"
#include "RaceBanner/Trolls.h"
#include "RaceBanner/Wizards.h"
#include "Badges/Bivouacking.h"
#include "Badges/Commando.h"
#include "Badges/Diplomat.h"
#include "Badges/DragonMaster.h"
#include "Badges/Flying.h"
#include "Badges/Forest.h"
#include "Badges/Fortified.h"
#include "Badges/Heroic.h"
#include "Badges/Hill.h"
#include "Badges/Merchant.h"
#include "Badges/Mounted.h"
#include "Badges/Pillaging.h"
#include "Badges/Seafaring.h"
#include "Badges/Spirit.h"
#include "Badges/Stout.h"
#include "Badges/Swamp.h"
#include "Badges/Underworld.h"
#include "Badges/Wealthy.h"
#include "mapAndPlayers.h"
#include "startupPhase.h"
#include "pickupRacePower.h"
#include "AggressiveStrategy.h"
#include "DefensiveStrategy.h"
#include "RandomStrategy.h"
#include "ModerateStrategy.h"
#include "ObserverPhase.h"
#include "ObserverStatistics.h"
#include "basicGameStasticsObserver.h"
#include "playerDominationObserverDecorator.h"
#include "playerHandsObserverDecorator.h"
#include "victoryCoinsObserverDecorator.h"

using namespace std;
//
//void test1() {
//	// below is the code for build up a map;
//
//	int numOfRegions = 0;
//	int edgeNumbers = 0;
//
//
//	do {
//		cout << "Please input the number of the regions for your Map: " << endl;
//		cin >> numOfRegions;
//	} while (numOfRegions <= 0);
//
//
//
//	Map *map1 = new Map(numOfRegions);
//
//	(*map1).printMap();
//
//	do {
//		cout << "Please input the number of the edges of your Map: " << endl;
//		cin >> edgeNumbers;
//	} while (edgeNumbers <= 0);
//
//	for (int i = 0; i < edgeNumbers; i++) {
//
//		cout << "********************************************************************" << endl;
//		int startNumRegion = 0, endNumRegion = 0;
//		do {
//			cout << "Please input the start Region number of the edge of your Map: " << endl;
//			cin >> startNumRegion;
//		} while ((startNumRegion < 0) || (startNumRegion >= numOfRegions));
//
//		do {
//			cout << "Please input the end Region number of the edge of your Map: " << endl;
//			cin >> endNumRegion;
//		} while ((endNumRegion < 0) || (endNumRegion >= numOfRegions) || (endNumRegion == startNumRegion));
//
//		(*map1).ad_edge(startNumRegion, endNumRegion);
//
//		(*map1).printMap();
//	}
//
//
//	// below is the code for display specific Region
//
//	int displayRegionID;
//
//	do {
//		cout << "Please input the ID of region you would like to display: " << endl;
//		cin >> displayRegionID;
//	} while ((displayRegionID < 0) || (displayRegionID >= numOfRegions));
//
//	map1->getRegion(displayRegionID)->printRegion();
//
//}
//


//void test2() {
//
//	int numOfPlayers;
//
//	do {
//		cout << "Please input the number of players:  " << endl;
//		cin >> numOfPlayers;
//	} while ((numOfPlayers < 2) || (numOfPlayers > 5));
//
//	MapLoader maploader1(numOfPlayers);
//
//	Map* map2 = maploader1.loadMap(true);
//	map2->isConnected();
//
//	map2->printMap();
//
//	system("pause");
//}


//
//void test3() {
//
//	Dice dice1;
//
//	for (int i = 0; i < 100; i++) {
//		
//		dice1.rollingDice(true);
//	}
//	
//	dice1.showPercentage();
//}
//
//
//void test5() {
//
//	cout << "1. Test Token and Coin object" << endl;
//
//	Token t1(5);
//	t1.showTokens();
//	Coins c1(10);
//	c1.showCoins();
//	cout << "2. Test RaceBanner and Badges" << endl;
//	Elves el1;
//	el1.show();
//	Alchemist al1;
//		al1.show();
//	cout << "3. Set up game piece" << endl;
//	LairFromTroll la1;
//	la1.show();
//	Fortesses fo1;
//	fo1.show();
//	Mountains mo1;
//	mo1.show();
//	Encampments en1;
//	en1.show();
//	TwoHolesInTheGround tw1;
//	tw1.show();
//	Heroes he1;
//	he1.show();
//	Dragon d1;
//	d1.show();
//	
//
//}
//
//vector<DeckCard> CreateDeckCardCombo(vector<Badges> &badgesArrayList, vector<RaceBanner> &raceBannerArrayList) {
//	vector<DeckCard> deckCardArrayList;
//	while (deckCardArrayList.size() < 14) {
//		int r1;
//		int r2;
//		if (badgesArrayList.size() == 1) {
//			r1 = 0;
//		}
//		else {
//			r1 = rand() % (badgesArrayList.size() - 1);
//		}
//		//cout << r1 << endl;
//		if (raceBannerArrayList.size() == 1) {
//			r2 = 0;
//		}
//		else {
//			r2 = rand() % (raceBannerArrayList.size() - 1);
//		}
//		//cout << r2 << endl;
//		vector<Badges>::iterator it1;
//		it1 = badgesArrayList.begin();
//		it1 = it1 + r1;
//		Badges tempBadges = *it1;
//		//cout << tempBadges.getbadgesName() << endl;
//		vector<RaceBanner>::iterator it2;
//		it2 = raceBannerArrayList.begin();
//		it2 = it2 + r2;
//		RaceBanner tempRaceBanner = *it2;
//		//cout << tempRaceBanner.getRaceName() << endl;
//		DeckCard tempDeckCard(tempBadges, tempRaceBanner);
//		deckCardArrayList.push_back(tempDeckCard);
//		badgesArrayList.erase(it1);
//		raceBannerArrayList.erase(it2);
//		// cout << deckCardArrayList.size() << " ";
//		// cout << badgesArrayList.size();
//		// cout << " " << raceBannerArrayList.size() << endl;
//	}
//	return deckCardArrayList;
//}
//
//void setUpGamePiece(int playernumber) {
//
//
//}
//
//void showSixComboCards(vector<DeckCard> deckCardArrayList) {
//
//	for (int i = 0; i < 6; i++) {
//		cout << i + 1 << ":" << endl;
//		cout << (deckCardArrayList)[i].getRaceBanner_().getRaceName() << " has "
//			<< (deckCardArrayList)[i].getRaceBanner_().getTokenAmount_() << " tokens." << endl;
//		cout << (deckCardArrayList)[i].getBadges_().getbadgesName() << " has "
//			<< (deckCardArrayList)[i].getBadges_().getTokenAmount_() << " tokens." << endl;
//		cout << "Total has " << (deckCardArrayList)[i].getInitialToken() << " tokens." << endl;
//		cout << "=========================================" << endl;
//	}
//}
//
//vector<DeckCard> updateDeckCardList(vector<DeckCard> deckCardArrayList, int number) {
//
//	vector<DeckCard>::iterator it1;
//	it1 = deckCardArrayList.begin();
//	it1 = it1 + (number - 1);
//	DeckCard tempBadges = *it1;
//	deckCardArrayList.erase(it1);
//	return deckCardArrayList;
//}
//

extern Map * ptPlayersMap;
extern vector<Players *> * ptPlayersPointerList;
extern std::vector<RaceBanner *> * raceBannerVector;
extern std::vector<Badges *> * specialPowerBadgesVector;
extern Observer * ObserverForPlayers;


void test11() {

	cout << "Welcome to Small World" << endl;

	mapAndPlayers * mapPlayerPointer(new mapAndPlayers());

	mapPlayerPointer->setupMapAndPlayers();

	ptPlayersMap->printMap();

	mapPlayerPointer->printPlayersList(ptPlayersPointerList);

	startupPhase * v(new startupPhase());
	cout << "*************Game Piece Creating*************" << endl; // **************************************
	cout << "We have following gamepieces: " << endl; // **************************************
	v->setGamePieceVector(); // create game piece

	delete mapPlayerPointer;

	mapPlayerPointer = nullptr;

	system("pause");
}



void test12()
{		
	cout << "Welcome to Small World!" << endl;

	mapAndPlayers * mapPlayerPointer(new mapAndPlayers());

	mapPlayerPointer->setupMapAndPlayers();

	ptPlayersMap->printMap();

	mapPlayerPointer->printPlayersList(ptPlayersPointerList);

	startupPhase * v(new startupPhase());
	cout << "*************Game Piece Creating*************" << endl; // **************************************
	cout << "We have following gamepieces: " << endl; // **************************************
	v->setGamePieceVector(); // create game piece



	system("pause");


	v->setRaceBannerVector();
	v->setSpecialPowerBadgesVector();

	std::cout << std::endl;
	ptPlayersMap->printMountainPieceRegion(); // print mount game piece on map
	std::cout << std::endl;
	std::cout << "After shuffling : " << std::endl;
	v->bannersShuffling();
	v->badgesShuffling();
	std::cout << std::endl;
	cout << "Player initial coins:" << endl;
	v->setPlayersCoin();

	std::cout << "show lost tribe region: " << std::endl;
	for(int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
	{
		
		if (ptPlayersMap->getRegion(i)->get_lost_tribe_count())
			std::cout << "Region " << i << " has a lost tribe! " << std::endl;
	}

	std::cout << "show mountain region: " << std::endl;
	for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
	{
		
		if (ptPlayersMap->getRegion(i)->get_mountain_count())
			std::cout << "Region " << i << " has a mountain! " << std::endl;
	}

	delete mapPlayerPointer;

	mapPlayerPointer = nullptr;

	system("pause");
}

void test13()
{
	cout << "Welcome to Small World" << endl;

	mapAndPlayers * mapPlayerPointer(new mapAndPlayers());

	mapPlayerPointer->setupMapAndPlayers();

	ptPlayersMap->printMap();

	mapPlayerPointer->printPlayersList(ptPlayersPointerList);

	startupPhase * v(new startupPhase());
	cout << "*************Game Piece Creating*************" << endl; // **************************************
	cout << "We have following gamepieces: " << endl; // **************************************
	v->setGamePieceVector(); // create game piece

	delete mapPlayerPointer;

	mapPlayerPointer = nullptr;

	system("pause");


	v->setRaceBannerVector();
	v->setSpecialPowerBadgesVector();

	std::cout << std::endl;
	ptPlayersMap->printMountainPieceRegion(); // print mount game piece on map
	std::cout << std::endl;
	std::cout << "After shuffling : " << std::endl;
	v->bannersShuffling();
	v->badgesShuffling();
	std::cout << std::endl;
	cout << "Player initial coins:" << endl;
	v->setPlayersCoin();

	//system("pause");

	
	showALLRacesBadges(); // for test

	cout << "Let's pick our combo" << endl;

	show6OrLessAvailableRacesBadges();

	pickupRacePower* pickupRactPowerAction(new pickupRacePower());
	pickupRactPowerAction->action();

	show6OrLessAvailableRacesBadges();

	system("pause");

	cout << "************************CONQUERS START***************************" << endl;

	cout << "------------------------First Turn----------------------------------" << endl;

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		std::cout << "************************************************************************************ " << endl;
		std::cout << "this is the attack from player " << (*iter)->get_id_player() << " : " <<  " \n " << endl;
		(*iter)->firstTurnAttack();
	}

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		(*iter)->scoringVictoryCoins();
	}
	
	showPlayersAtTurnEnd();

	system("pause");

	gameTurnMarker = 1;

	do
	{
		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			std::cout << "this is the attack from player " << (*iter)->get_id_player() << " : " << " \n " << endl;
			(*iter)->followingTurnAttack();
		}

		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			(*iter)->scoringVictoryCoins();
		}

		showPlayersAtTurnEnd();
		gameTurnMarker++;

		system("pause");
	} while (gameTurnMarker != 10);
	

}


void test14()
{
	cout << "Welcome to Small World" << endl;

	mapAndPlayers * mapPlayerPointer(new mapAndPlayers());

	mapPlayerPointer->setupMapAndPlayers();

	ptPlayersMap->printMap();

	mapPlayerPointer->printPlayersList(ptPlayersPointerList);

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		(*iter)->attach(new ObserverPhase);
	}

	if (ptPlayersPointerList->size() >1)
		ptPlayersPointerList->at(1)->set_pt_strategy(new AggressiveStrategy);
	if (ptPlayersPointerList->size() > 2)
		ptPlayersPointerList->at(2)->set_pt_strategy(new DefensiveStrategy);
	if (ptPlayersPointerList->size() > 3)
		ptPlayersPointerList->at(3)->set_pt_strategy(new ModerateStrategy);
	if (ptPlayersPointerList->size() > 4)
		ptPlayersPointerList->at(4)->set_pt_strategy(new RandomStrategy);

	//ObserverForPlayers = new ObserverStatistics(ptPlayersPointerList->size());

	startupPhase * v(new startupPhase());
	cout << "*************Game Piece Creating*************" << endl; // **************************************
	cout << "We have following gamepieces: " << endl; // **************************************
	v->setGamePieceVector(); // create game piece

	delete mapPlayerPointer;

	mapPlayerPointer = nullptr;

	system("pause");


	v->setRaceBannerVector();
	v->setSpecialPowerBadgesVector();

	std::cout << std::endl;
	ptPlayersMap->printMountainPieceRegion(); // print mount game piece on map
	std::cout << std::endl;
	std::cout << "After shuffling : " << std::endl;
	v->bannersShuffling();
	v->badgesShuffling();
	std::cout << std::endl;
	cout << "Player initial coins:" << endl;
	v->setPlayersCoin();

	//system("pause");


	showALLRacesBadges(); // for test

	cout << "Let's pick our combo" << endl;

	show6OrLessAvailableRacesBadges();

	pickupRacePower* pickupRactPowerAction(new pickupRacePower());
	pickupRactPowerAction->action();

	show6OrLessAvailableRacesBadges();

	system("pause");

	cout << "************************CONQUERS START***************************" << endl;

	cout << "------------------------First Turn----------------------------------" << endl;

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		std::cout << "************************************************************************************ " << endl;
		std::cout << "this is the attack from player " << (*iter)->get_id_player() << " : " << " \n " << endl;
		(*iter)->firstTurnAttack();
	}

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		(*iter)->scoringVictoryCoins();
	}

	showPlayersAtTurnEnd();

	system("pause");

	gameTurnMarker = 1;

	do
	{
		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			std::cout << "this is the attack from player " << (*iter)->get_id_player() << " : " << " \n " << endl;
			(*iter)->followingTurnAttack();
		}

		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			(*iter)->scoringVictoryCoins();
		}

		showPlayersAtTurnEnd();
		gameTurnMarker++;

		system("pause");
	} while (gameTurnMarker != 10);


}


void test15()
{
	cout << "Welcome to Small World" << endl;

	mapAndPlayers * mapPlayerPointer(new mapAndPlayers());

	mapPlayerPointer->setupMapAndPlayers();

	ptPlayersMap->printMap();

	mapPlayerPointer->printPlayersList(ptPlayersPointerList);

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		(*iter)->attach(new ObserverPhase);
	}

	if (ptPlayersPointerList->size() > 1)
		ptPlayersPointerList->at(1)->set_pt_strategy(new AggressiveStrategy);
	if (ptPlayersPointerList->size() > 2)
		ptPlayersPointerList->at(2)->set_pt_strategy(new DefensiveStrategy);
	if (ptPlayersPointerList->size() > 3)
		ptPlayersPointerList->at(3)->set_pt_strategy(new ModerateStrategy);
	if (ptPlayersPointerList->size() > 4)
		ptPlayersPointerList->at(4)->set_pt_strategy(new RandomStrategy);

	//ObserverForPlayers = new ObserverStatistics(ptPlayersPointerList->size());

	startupPhase * v(new startupPhase());
	cout << "*************Game Piece Creating*************" << endl; // **************************************
	cout << "We have following gamepieces: " << endl; // **************************************
	v->setGamePieceVector(); // create game piece

	delete mapPlayerPointer;

	mapPlayerPointer = nullptr;

	system("pause");


	v->setRaceBannerVector();
	v->setSpecialPowerBadgesVector();

	std::cout << std::endl;
	ptPlayersMap->printMountainPieceRegion(); // print mount game piece on map
	std::cout << std::endl;
	std::cout << "After shuffling : " << std::endl;
	v->bannersShuffling();
	v->badgesShuffling();
	std::cout << std::endl;
	cout << "Player initial coins:" << endl;
	v->setPlayersCoin();

	//system("pause");


	showALLRacesBadges(); // for test

	cout << "Let's pick our combo" << endl;

	show6OrLessAvailableRacesBadges();

	pickupRacePower* pickupRactPowerAction(new pickupRacePower());
	pickupRactPowerAction->action();

	show6OrLessAvailableRacesBadges();

	system("pause");

	cout << "************************CONQUERS START***************************" << endl;

	cout << "------------------------First Turn----------------------------------" << endl;

	basicGameStasticsObserver *  BGSObserver = new basicGameStasticsObserver();
	playerDominationObserverDecorator * PDODecorator = new playerDominationObserverDecorator(BGSObserver);
	playerHandsObserverDecorator * PHODecorator = new playerHandsObserverDecorator(BGSObserver);
	victoryCoinsObserverDecorator * VCODecorator = new victoryCoinsObserverDecorator(BGSObserver);

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		(*iter)->attach(BGSObserver);
	}

	int userInputOptionNumber = 0;

	std::cout << "\nWould you like adding a player_Domination_Observer_Decorator ? " << std::endl;
	std::cin >> userInputOptionNumber;

	if (userInputOptionNumber)
	{
		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			(*iter)->attach(PDODecorator);
		}

		for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
		{
			ptPlayersMap->getRegion(i)->attach(PDODecorator);
		}
	}

	std::cout << "\nWould you like adding a player_Hands_Observer_Decorator ? " << std::endl;
	std::cin >> userInputOptionNumber;

	if (userInputOptionNumber)
	{
		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			(*iter)->attach(PHODecorator);
		}
	}

	std::cout << "\nWould you like adding a victory_Coins_Observer_Decorator ? " << std::endl;
	std::cin >> userInputOptionNumber;

	if (userInputOptionNumber)
	{
		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			(*iter)->attach(VCODecorator);
		}
	}

	bool addObserverOrRemoval = true;


	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		std::cout << "************************************************************************************ " << endl;
		std::cout << "this is the attack from player " << (*iter)->get_id_player() << " : " << " \n " << endl;
		(*iter)->firstTurnAttack();
	}

	for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		(*iter)->scoringVictoryCoins();
	}

	showPlayersAtTurnEnd();

	system("pause");

	gameTurnMarker = 1;

	do
	{
		if (addObserverOrRemoval)
		{
			if (!(ptPlayersPointerList->at(0)->containObserver(PDODecorator)))
			{
				std::cout << "\nWould you like adding a player_Domination_Observer_Decorator ? " << std::endl;
				std::cin >> userInputOptionNumber;

				if (userInputOptionNumber)
				{
					for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
					{
						(*iter)->attach(PDODecorator);
					}
				}
			}

			if (!(ptPlayersPointerList->at(0)->containObserver(PHODecorator)))
			{
				std::cout << "\nWould you like adding a player_Hands_Observer_Decorator ? " << std::endl;
				std::cin >> userInputOptionNumber;

				if (userInputOptionNumber)
				{
					for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
					{
						(*iter)->attach(PHODecorator);
					}
				}
			}

			if (!(ptPlayersPointerList->at(0)->containObserver(VCODecorator)))
			{
				std::cout << "\nWould you like adding a victory_Coins_Observer_Decorator ? " << std::endl;
				std::cin >> userInputOptionNumber;

				if (userInputOptionNumber)
				{
					for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
					{
						(*iter)->attach(VCODecorator);
					}
				}
			}

			std::cout << "\nWould you remove some Decorator ? " << std::endl;
			std::cin >> userInputOptionNumber;

			if (userInputOptionNumber)
			{
				if ((ptPlayersPointerList->at(0)->containObserver(PDODecorator)))
				{
					std::cout << "\nWould you like to remove a player_Domination_Observer_Decorator ? " << std::endl;
					std::cin >> userInputOptionNumber;

					if (userInputOptionNumber)
					{
						for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
						{
							(*iter)->detach(PDODecorator);
						}
					}

					if (ptPlayersPointerList->at(0)->containObserver(PDODecorator))
						std::cout << "Detach failed! please note !" << endl;
				}

				if ((ptPlayersPointerList->at(0)->containObserver(PHODecorator)))
				{
					std::cout << "\nWould you like to remove a player_Hands_Observer_Decorator ? " << std::endl;
					std::cin >> userInputOptionNumber;

					if (userInputOptionNumber)
					{
						for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
						{
							(*iter)->detach(PHODecorator);
						}
					}

					if (ptPlayersPointerList->at(0)->containObserver(PHODecorator))
						std::cout << "Detach failed! please note !" << endl;
				}

				if ((ptPlayersPointerList->at(0)->containObserver(VCODecorator)))
				{
					std::cout << "\nWould you like to remove a victory_Coins_Observer_Decorator ? " << std::endl;
					std::cin >> userInputOptionNumber;

					if (userInputOptionNumber)
					{
						for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
						{
							(*iter)->detach(VCODecorator);
						}
					}

					if (ptPlayersPointerList->at(0)->containObserver(VCODecorator))
						std::cout << "Detach failed! please note !" << endl;
				}
			}

			std::cout << "\nWould you like to set Decorators in the next turn? " << std::endl;
			std::cin >> userInputOptionNumber;

			if (userInputOptionNumber)
				addObserverOrRemoval = true;
			else addObserverOrRemoval = false;
		}



		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			std::cout << "this is the attack from player " << (*iter)->get_id_player() << " : " << " \n " << endl;
			(*iter)->followingTurnAttack();
		}

		for (auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
		{
			(*iter)->scoringVictoryCoins();
		}

		showPlayersAtTurnEnd();
		gameTurnMarker++;

		system("pause");
	} while (gameTurnMarker != 10);

}

int main() {

	srand((unsigned)time(NULL));
	
	//test11();

	//test12(); / there exit a sudden exit NOT solved.

	test15();

	//test2();
	

	//int testNumber= 0;

	//int toBeContinue = 0;

	//do {
	//	do {
	//		cout << "which test module would want to test? option: 1 2 3 4 5  " << endl;
	//		cin >> testNumber;
	//	} while ((testNumber <= 0) || (testNumber >= 6));

	//	switch (testNumber)
	//	{
	//	case 1: test1(); break;
	//	case 2: test2(); break;
	//	case 3: test3(); break;
	//	case 4: {
	//		//badges
	//		Alchemist al1;
	//		Berserk be1;
	//		Bivouacking bi1;
	//		Commando co1;
	//		Diplomat di1;
	//		DragonMaster dr1;
	//		Flying fl1;
	//		Forest fo1;
	//		Fortified for1;
	//		Heroic he1;
	//		Hill hi1;
	//		Merchant me1;
	//		Mounted mo1;
	//		Pillaging pi1;
	//		Seafaring se1;
	//		Spirit sp1;
	//		Stout st1;
	//		Swamp sw1;
	//		Underworld un1;
	//		Wealthy we1;



	//		//racebanner
	//		Amazons am1;
	//		Elves el1;
	//		Dwarves Dw1;
	//		Ghouls gh1;
	//		Giants gi1;
	//		Halflings ha1;
	//		Humans hu1;
	//		Orcs or1;
	//		Ratmen rl1;
	//		Skeletons sk1;
	//		Sorceres so1;
	//		Tritons tri1;
	//		Trolls tro1;
	//		Wizards wi1;

	//		vector<Badges> badgesArrayList;
	//		vector<RaceBanner> raceBannerArrayList;
	//		// Create badges and raceBanners
	//		raceBannerArrayList.push_back(am1);
	//		raceBannerArrayList.push_back(el1);
	//		raceBannerArrayList.push_back(Dw1);
	//		raceBannerArrayList.push_back(gh1);
	//		raceBannerArrayList.push_back(Dw1);
	//		raceBannerArrayList.push_back(ha1);
	//		raceBannerArrayList.push_back(hu1);
	//		raceBannerArrayList.push_back(or1);
	//		raceBannerArrayList.push_back(rl1);
	//		raceBannerArrayList.push_back(sk1);
	//		raceBannerArrayList.push_back(so1);
	//		raceBannerArrayList.push_back(tri1);
	//		raceBannerArrayList.push_back(tro1);
	//		raceBannerArrayList.push_back(wi1);


	//		badgesArrayList.push_back(al1);
	//		badgesArrayList.push_back(be1);
	//		badgesArrayList.push_back(bi1);
	//		badgesArrayList.push_back(co1);
	//		badgesArrayList.push_back(di1);
	//		badgesArrayList.push_back(dr1);
	//		badgesArrayList.push_back(fl1);
	//		badgesArrayList.push_back(fo1);
	//		badgesArrayList.push_back(for1);
	//		badgesArrayList.push_back(he1);
	//		badgesArrayList.push_back(hi1);
	//		badgesArrayList.push_back(me1);
	//		badgesArrayList.push_back(mo1);
	//		badgesArrayList.push_back(pi1);
	//		badgesArrayList.push_back(se1);
	//		badgesArrayList.push_back(sp1);
	//		badgesArrayList.push_back(st1);
	//		badgesArrayList.push_back(sw1);
	//		badgesArrayList.push_back(un1);
	//		badgesArrayList.push_back(we1);

	//		Players p1;
	//		cout << "The initial player properties:" << endl;
	//		p1.show();
	//		cout << "Player start to play. " << "The first five combos are:" << endl;
	//		//Create Race Combo
	//		vector<DeckCard> deckCardArrayList = CreateDeckCardCombo(badgesArrayList, raceBannerArrayList);

	//		//Show first five deck combo
	//		showSixComboCards(deckCardArrayList);

	//		int comboNumber = 1;
	//		do {
	//			cout << "Please pick one deck combo: " << endl;
	//			if (comboNumber > 6 || comboNumber < 1) {
	//				cout << "Wrong number! Please enter a correct number." << endl;
	//			}
	//			cin >> comboNumber;
	//		} while (comboNumber > 6 || comboNumber < 1);

	//		p1.pick_race(deckCardArrayList[comboNumber - 1], comboNumber);
	//		// updated deckCardList
	//		deckCardArrayList = updateDeckCardList(deckCardArrayList, comboNumber);
	//		cout << "All right!!! Let's print out all your properties" << endl;
	//		p1.show();
	//		cout << "Test for scores method" << endl;

	//		cout << "Test for conquer methods" << endl;
	//		Region r1;
	//		p1.conquers(r1);

	//		deckCardArrayList.clear();
	//		badgesArrayList.clear();
	//		raceBannerArrayList.clear(); }; break;
	//	case 5: test5(); break;
	//	default: break;
	//	}

	//	cout << "Would you like another test?  0 or 1 " << endl;

	//	cin >> toBeContinue;

	//} while (toBeContinue);


	//cout << "This is the end of demo, thank you for your time! Have a good day! " << endl;

	//system("pause");


		//Map* map1 = maploader1.loadMap(true);

		//map1->isConnected();
		

		//Graph graph1(5);
	//add_edge(0, 1, graph1);
	//add_edge(1, 2, graph1);
	//add_edge(2, 3, graph1);
	//add_edge(3, 4, graph1);
	//add_edge(4, 0, graph1);

	//const Graph graph2(graph1);

	//std::ofstream ofs("Graph1.txt");
	//boost::archive::text_oarchive oa(ofs);
	//oa << graph2;

	/*const Region region1;

	std::ofstream ofs("Region1.txt");

	boost::archive::text_oarchive oa(ofs);

	oa << region1; */

	/*Region region2;

	std::ifstream ifs("Region1.txt");

	boost::archive::text_iarchive ia(ifs);

	ia >> region2;

	cout << region2.getOwner() << "  " << region2.getRegionID() << endl;*/


		//Map *map1 = new Map(23, true);

		//const Map map2(*map1);

		//std::ofstream ofs2("Map2.txt");

		//boost::archive::text_oarchive oa2(ofs2);

		//oa2 << map2;

		//ofs2.close();


	
/*
	Map map3;

	std::ifstream ifs2("Map2.txt");

	boost::archive::text_iarchive ia2(ifs2);

	ia2 >> map3;

	ifs2.close();
	
		cout << "this map is connected? " << boolalpha << (map3).isConnected() << endl;
		cout << "********************************************************************" << endl;

	for (int itt = 0; itt < (map3).retAdjRegionsNumList(4)->size(); itt++) {
		cout << "The adjacent nodes' IDs are  " << (map3).retAdjRegionsNumList(4)->at(itt) << endl;
	}

	cout << "the region ID of Region 1 is " << map3.getRegion(1)->getRegionID() << endl;

	delete map1;
	map1 = nullptr;*/



	//Dice dice1;

	//for (int i = 0; i < 100; i++) {
	//	
	//	dice1.rollingDice(true);
	//}
	//
	//dice1.showPercentage();



	//MapLoader maploader1(5);

	//Map* map1 = maploader1.loadMap(true);

	//map1->isConnected();

	//system("pause");

}
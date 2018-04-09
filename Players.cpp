//
// Created by vince on 2018/2/10.
//
//rwar

#include "Players.h"
#include "pickupRacePower.h"
#include "Map.h"
#include <algorithm>
#include "Strategy.h"
#include "Observer.h"

extern int coin1 = 35;
extern int coin3 = 20;
extern int coin5 = 24;
extern int coin10 = 30;
extern int gameTurnMarker;
class Map;

extern Map * ptPlayersMap;
extern vector<Players *> * ptPlayersPointerList;
extern std::vector<RaceBanner *> * raceBannerVector;
extern std::vector<Badges *> * specialPowerBadgesVector;
extern Observer * ObserverForPlayers;

Players::Players() {
	token = 0;
	coins = 5;
	setDice(*(new Dice()));
}

Players::~Players() {

}

const DeckCard &Players::getDeckCard() const {
	return currentdeckCard;
}

void Players::pick_race(const DeckCard &deckCard, int number) {
	Players::currentdeckCard = deckCard;
	Players::coins = getCoins().getCoinsAmount() - number + 1;
	Players::token = currentdeckCard.getInitialToken();
}

const Coins &Players::getCoins() const {
	return coins;
}

void Players::scores(const Coins &coins) {
	Players::coins = coins;
}

const Token &Players::getToken() const {
	return token;
}

void Players::setToken(const Token &token) {
	Players::token = token;
}

void Players::show() {
	currentdeckCard.showDeckCard();
	std::cout << "Token amount is " << token.getTokenAmount() << std::endl;
	std::cout << "Coin amount is " << coins.getCoinsAmount() << std::endl;
	std::cout << "Region Amount is " << regionList.size() << std::endl;
	dice.showPercentage();
}

const Dice &Players::getDice() const {
	return dice;
}

void Players::setDice(const Dice &dice) {
	Players::dice = dice;
}

const vector<Region> &Players::getRegionList() const {
	return regionList;
}

void Players::setRegionList(const vector<Region> &regionList) {
	Players::regionList = regionList;
}

void Players::conquers(Region region) {
	std::cout << "Start to couquer" << std::endl;
};

void Players::addControlledRegionID(int ID_region)
{
	controlledRegionList.push_back(ID_region);
	sort(controlledRegionList.begin(), controlledRegionList.end());
}

void Players::removeControlledRegionID(int ID_region)
{
	for(auto iter = controlledRegionList.begin(); iter != controlledRegionList.end(); )
	{
		if ((*iter) == ID_region) iter = controlledRegionList.erase(iter);
		else ++iter;
	}
	controlledRegionList.shrink_to_fit();
	
}

bool Players::containRegionID(vector<int> * const regionList, int ID_Region)
{
	if (regionList->empty()) return false;

	for (auto iter = regionList->begin(); iter != regionList->end(); ++iter)
	{
		if ((*iter) == ID_Region) return true;
	}
	return false;
}

void Players::updateAdjacentRegionID()
{
	//std::cout << "current controlledRegionList ::  " << controlledRegionList.size() << " items" << endl;
	//printRegionList(controlledRegionList);

	adjacentRegionList.clear();

	vector<int>  tempAdjRegionIDVector;
	vector<int>* tempIntVectorPointer = nullptr;

	if (!(controlledRegionList.empty()))
	{
		for (auto iter = controlledRegionList.begin(); iter != controlledRegionList.end(); ++iter)
		{
			
			int currentRegionID = *iter;
			tempIntVectorPointer = ptPlayersMap->retAdjRegionsNumList(currentRegionID);
			tempAdjRegionIDVector.assign((*tempIntVectorPointer).begin(), (*tempIntVectorPointer).end());
			
			for (auto iterr = tempAdjRegionIDVector.begin(); iterr != tempAdjRegionIDVector.end(); ++iterr)
			{
				if ((!(containRegionID((&adjacentRegionList), (*iterr)))) &&(this->get_id_player() != ptPlayersMap->getRegion(*iterr)->get_owner()))
				{
					if (ptPlayersMap->getRegion(*iterr)->get_coastal_region_count() != 1) 
						adjacentRegionList.push_back(*iterr);
					else if (this->get_current_power()->getbadgesName() == static_cast<string>("Seafaring"))
						adjacentRegionList.push_back(*iterr);
				}
					
			}
			tempIntVectorPointer = nullptr;
			tempAdjRegionIDVector.clear();
		}
	}
	
	std::cout << "Player " << this->get_id_player() << " has " << turnRegionConquerList.size() << " region" << endl;
	printRegionList(turnRegionConquerList);
	
	if (!(turnRegionConquerList.empty()))
	{
		for (auto iter = turnRegionConquerList.begin(); iter != turnRegionConquerList.end(); ++iter)
		{
			int currentRegionID = *iter;
			tempIntVectorPointer = ptPlayersMap->retAdjRegionsNumList(currentRegionID);
			tempAdjRegionIDVector.assign((*tempIntVectorPointer).begin(), (*tempIntVectorPointer).end());
	
			for (auto iterr = tempAdjRegionIDVector.begin(); iterr != tempAdjRegionIDVector.end(); ++iterr)
			{
				if ((!(containRegionID((&adjacentRegionList), (*iterr)))) && ((this->get_id_player() != ptPlayersMap->getRegion(*iterr)->get_owner())))
				{
					//(!((this->get_current_race()->getRaceName() == ptPlayersMap->getRegion(*iterr)->get_cu_race_name()) ||
					//(this->get_declined_race()->getRaceName() == ptPlayersMap->getRegion(*iterr)->get_de_race_name()))))
					if (ptPlayersMap->getRegion(*iterr)->get_coastal_region_count() != 1)
						adjacentRegionList.push_back(*iterr);
					else if (this->get_current_power()->getbadgesName() == static_cast<string>("Seafaring"))
						adjacentRegionList.push_back(*iterr);
				}
					
			}

			tempIntVectorPointer = nullptr;
			tempAdjRegionIDVector.clear();
		}
	}

	sort(adjacentRegionList.begin(), adjacentRegionList.end());

	adjacentRegionList.shrink_to_fit();
}

void Players::addTurnRegionConquerList(int ID_region)
{
	if (!(containRegionID((&turnRegionConquerList), (ID_region)))) turnRegionConquerList.push_back(ID_region);

	if (turnRegionConquerList.size() != 0)
		sort(turnRegionConquerList.begin(), turnRegionConquerList.end());
}

void Players::removeTurnRegionConquerList(int ID_region)
{
	if ((turnRegionConquerList.empty())|| (!(containRegionID((&turnRegionConquerList), (ID_region)))))
	{
		std::cout << "the region you would like to remove from turnRegionConquerList does NOT exist! " << std::endl;
		return;
	}

	for (auto iter = turnRegionConquerList.begin(); iter != turnRegionConquerList.end(); )
	{
		if ((*iter) == ID_region) iter = turnRegionConquerList.erase(iter);
		else ++iter;
	}
	turnRegionConquerList.shrink_to_fit();

	if (turnRegionConquerList.size() != 0)
		sort(turnRegionConquerList.begin(), turnRegionConquerList.end());
}

void Players::printCoins() const
{
	std::cout << " " << get_coin_1() << "  1_tokens , " << get_coin_3() << "  3_coins , " << get_coin_5() << "  5_coins, " << get_coin_10() << " 10_coins. " << endl;
}


RaceBanner * Players::get_current_race() const
{
	return currentRace;
}

void Players::set_current_race(RaceBanner* const current_race)
{
	currentRace = current_race;
}

Badges* Players::get_current_power() const
{
	return currentPower;
}

void Players::set_current_power(Badges* const current_power)
{
	currentPower = current_power;
}


void Players::pick_race() {
	set_program_status("Player pick a race");
	notify();

	std::cout << "\nPlayer " << this->get_id_player() << ", please input your desired race ID: \n" << endl;

	//showAllRacesBadges();
	show6OrLessAvailableRacesBadges(); 
	int raceNumber = -1;
	if (pt_strategy_) raceNumber = pt_strategy_->strategyRaceSelection(this); // strategy input problematic!!!!!!!!!!!!!!!!!!!!!!!!!
	else raceNumber = getNumberInputForRace();
	pick_race(raceNumber);
}


void Players::pick_race(int ID_RaceOrBadge)
{
	set_program_status("Player pick a race");
	notify();

	reduceCoinForRaceSelection(ID_RaceOrBadge);

	set_current_race(raceBannerVector->at(ID_RaceOrBadge));
	raceBannerVector->at(ID_RaceOrBadge)->set_is_available(false);
	raceBannerVector->at(ID_RaceOrBadge)->set_point_player(this);
	// pick powers
	set_current_power(specialPowerBadgesVector->at(ID_RaceOrBadge));
	specialPowerBadgesVector->at(ID_RaceOrBadge)->set_is_available(false);
	specialPowerBadgesVector->at(ID_RaceOrBadge)->set_point_player(this);

	this->set_in_hand_solider_current_race(currentRace->getTokenAmount_() + currentPower->getTokenAmount_());
	if (this->get_current_race()->getRaceName() == static_cast<string>("Amazons")) 
		this->set_in_hand_solider_current_race(this->get_in_hand_solider_current_race() + 4);

	if (currentPower->getbadgesName() == (static_cast<string>("Bivouacking")))     set_in_hand_encampments(5);
	else if (currentPower->getbadgesName() == (static_cast<string>("DragonMaster"))) set_in_hand_dragon(1);
	else if (currentPower->getbadgesName() == (static_cast<string>("Fortified"))) set_in_hand_fortresses(6);
	else if (currentPower->getbadgesName() == (static_cast<string>("Heroic"))) set_in_handhero(2);
	else if (currentRace->getRaceName() == (static_cast<string>("Trolls"))) set_in_hand_troll_lairs(10);
	else if (currentRace->getRaceName() == (static_cast<string>("Halfings"))) set_in_hand_hole_in_the_ground(2);

	std::cout << "Player " << this->get_id_player() << " chosed NO." << ID_RaceOrBadge  <<  " race " << currentRace->getRaceName() << " and power " << currentPower->getbadgesName() <<  endl;
	std::cout << "**********************************************************************************************" << endl;

	notify();
	(observerVector.at(0))->showStatus();
	ObserverForPlayers->showStatus();
}

void Players::reduceCoinForRaceSelection(int ID_RaceOrBadge)
{
	int reductionNumber = raceSelectCoinReduction(ID_RaceOrBadge);
	for (int i = 0; i < reductionNumber; i++)
	{
		reduce_coin_1();
	}
};

int Players::raceSelectCoinReduction(int ID_RaceOrBadge)
{
	int reductionNumber = 0;
	for (auto iter = raceBannerVector->begin(); iter != raceBannerVector->end(); ++iter)
	{
		if ((*iter)->get_id_race() == ID_RaceOrBadge) break;
		if ((*iter)->is_available()) reductionNumber++;
	}

	return reductionNumber;
}

bool Players::isAttckableRegion(int ID_Region)
{
	if (gameTurnMarker == 1)
	{
		if (ptPlayersMap->getRegion(ID_Region)->get_is_at_boundary_of_map()) return false;
	}

	if (this->get_id_player() == ptPlayersMap->getRegion(ID_Region)->get_owner())
	{
		std::cout << "This is your own Region, not attackable! please re-select another Region!" << endl;
		return false;
	}

	if ((!(containRegionID(&adjacentRegionList, ID_Region))) && 
		(this->get_current_power()->getbadgesName() != static_cast<string>("Flying")))
		return false;

	if ((!(containRegionID(&adjacentRegionList, ID_Region)))&&
		(this->get_current_race()->getRaceName() != static_cast<string>("Halfings"))) 
		return false;

	if ((ptPlayersMap->getRegion(ID_Region)->get_coastal_region_count() == 1) && 
		((this->get_current_power()->getbadgesName() != static_cast<string>("Seafaring")) || (this->get_current_race()->getRaceName() != static_cast<string>("Tritons")) )) 
		return false;

	return true;
};

void Players::loseAndWithdraws(int ID_Region)
{
	set_program_status("Player loss and withdraws");
	notify();
	

	if (ptPlayersMap->getRegion(ID_Region)->get_owner() == (-1))
	{
		ptPlayersMap->getRegion(ID_Region)->set_lost_tribe_count(0);
		return;
	}
	int returnSoildier = 0;

	Players * playerToGetReturnSolider = ptPlayersPointerList->at(ptPlayersMap->getRegion(ID_Region)->get_owner());

	if (ptPlayersMap->getRegion(ID_Region)->get_solider_current_race()>0)
	{
		returnSoildier = ptPlayersMap->getRegion(ID_Region)->get_solider_current_race();
		ptPlayersMap->getRegion(ID_Region)->set_cu_race_name("");
		ptPlayersMap->getRegion(ID_Region)->set_owner(-1);
		ptPlayersMap->getRegion(ID_Region)->set_solider_current_race(0);
		playerToGetReturnSolider->set_in_hand_solider_current_race(playerToGetReturnSolider->get_in_hand_solider_current_race() +
			((ptPlayersMap->getRegion(ID_Region)->get_cu_race_name() == static_cast<string>("Elves"))||(ptPlayersMap->getRegion(ID_Region)->get_de_race_name() == static_cast<string>("Elves"))) ? returnSoildier : returnSoildier - 1);
		vector<int> tempVector = playerToGetReturnSolider->get_controlled_region_list();
		if (containRegionID((&tempVector), ID_Region)) playerToGetReturnSolider->removeControlledRegionID(ID_Region);
		//printRegionList(tempVector);
		tempVector.clear();
		tempVector.shrink_to_fit();
		tempVector = playerToGetReturnSolider->get_turn_region_conquer_list();
		if (containRegionID((&tempVector), ID_Region)) playerToGetReturnSolider->removeTurnRegionConquerList(ID_Region);
		//printRegionList(tempVector);
		if (ptPlayersMap->getRegion(ID_Region)->get_solider_declined_race() > 0)
		{
			std::cout << "error, have both current race soliders and declined soliders in this region" << std::endl;
			system("pause");
		}
		
	}
	else if (ptPlayersMap->getRegion(ID_Region)->get_solider_declined_race()>0)
	{
		returnSoildier = ptPlayersMap->getRegion(ID_Region)->get_solider_declined_race();
		ptPlayersMap->getRegion(ID_Region)->set_de_race_name("");
		ptPlayersMap->getRegion(ID_Region)->set_owner(-1);
		ptPlayersMap->getRegion(ID_Region)->set_solider_declined_race(0);
		playerToGetReturnSolider->set_in_hand_solider_declined_race(playerToGetReturnSolider->get_in_hand_solider_declined_race() + 
			((ptPlayersMap->getRegion(ID_Region)->get_cu_race_name() == static_cast<string>("Elves")) || (ptPlayersMap->getRegion(ID_Region)->get_de_race_name() == static_cast<string>("Elves"))) ? returnSoildier : returnSoildier - 1);
		vector<int> tempVector = playerToGetReturnSolider->get_controlled_region_list();
		if (containRegionID((&tempVector), ID_Region)) playerToGetReturnSolider->removeControlledRegionID(ID_Region);
		//printRegionList(tempVector);
		tempVector.clear();
		tempVector.shrink_to_fit();
		tempVector = playerToGetReturnSolider->get_turn_region_conquer_list();
		if (containRegionID((&tempVector), ID_Region)) playerToGetReturnSolider->removeTurnRegionConquerList(ID_Region);
		//printRegionList(tempVector);

		if (ptPlayersMap->getRegion(ID_Region)->get_solider_current_race()>0)
		{
			std::cout << "error, have both current race soliders and declined soliders in this region" << std::endl;
			system("pause");
		}
			
	}

	//playerToGetReturnSolider->returnGamePiecesFromMap(ID_Region);

	//playerToGetReturnSolider->update_active_race_control_region_list();
	//playerToGetReturnSolider->update_declined_race_control_region_list();
	update_active_race_control_region_list();
	update_declined_race_control_region_list();
	notify();
	(observerVector.at(0))->showStatus();
	ObserverForPlayers->showStatus();
}


void Players::normalDeploy()
{
	set_program_status("Player deploy");
	notify();

	std::cout << "\nNow please deploy your solider for defence: \n" << std::endl;
	vector<int> currentControlRegionList;

	if (!controlledRegionList.empty()) currentControlRegionList.insert(currentControlRegionList.end(), controlledRegionList.begin(), controlledRegionList.end());
	if (!turnRegionConquerList.empty()) currentControlRegionList.insert(currentControlRegionList.end(), turnRegionConquerList.begin(), turnRegionConquerList.end());

	if (!currentControlRegionList.empty())
	{
		int numTempReturnSolidier(0);
		for (auto iter = currentControlRegionList.begin(); iter != currentControlRegionList.end(); ++iter)
		{
			if (ptPlayersMap->getRegion(*iter)->get_solider_current_race() > 0)
			{
				numTempReturnSolidier = ptPlayersMap->getRegion(*iter)->get_solider_current_race() - 1;
				ptPlayersMap->getRegion(*iter)->set_solider_current_race(1);
				this->set_in_hand_solider_current_race(numTempReturnSolidier + this->get_in_hand_solider_current_race());
			}
		}

		if (this->get_current_race()->getRaceName() == static_cast<string>("Amazons") && (this->get_in_hand_solider_current_race() < 4 ))
		{
			do
			{
				abandonAreas(); // as long as abandonAreas works well, this should be fine
			} while (this->get_in_hand_solider_current_race() >= 4);
		}
		
		if (this->get_current_race()->getRaceName() == static_cast<string>("Amazons") && (this->get_in_hand_solider_current_race() > 4))
		{
			for (auto iter = currentControlRegionList.begin(); iter != currentControlRegionList.end(); ++iter)
			{
				if ((ptPlayersMap->getRegion(*iter)->get_solider_current_race() > 0) && (this->get_in_hand_solider_current_race()-4 > 0))
				{
					std::cout << "Please input the number of active race soliders you would like to put in Region " << (*iter) << " : " << endl;
					int tempUserInputInt = get_correct_inputNumberOfChoice(0, this->get_in_hand_solider_current_race()-4);

					ptPlayersMap->getRegion(*iter)->set_solider_current_race(tempUserInputInt + ptPlayersMap->getRegion(*iter)->get_solider_current_race());
					this->set_in_hand_solider_current_race(this->get_in_hand_solider_current_race() - tempUserInputInt);
				}
			}
		}
		else
		{
			for (auto iter = currentControlRegionList.begin(); iter != currentControlRegionList.end(); ++iter)
			{
				if ((ptPlayersMap->getRegion(*iter)->get_solider_current_race() > 0) && (this->get_in_hand_solider_current_race() > 0))
				{
					std::cout << "Please input the number of active race soliders you would like to put in Region " << (*iter) << " : " << endl;
					int tempUserInputInt = get_correct_inputNumberOfChoice(0, this->get_in_hand_solider_current_race());

					ptPlayersMap->getRegion(*iter)->set_solider_current_race(tempUserInputInt + ptPlayersMap->getRegion(*iter)->get_solider_current_race());
					this->set_in_hand_solider_current_race(this->get_in_hand_solider_current_race() - tempUserInputInt);
				}
			}
		}
		

		sort(currentControlRegionList.begin(), currentControlRegionList.end());

		//showTroopStatusAfterDeploy(currentControlRegionList);

		//std::cout << "Your finish redeploy!" << endl;
		//std::cout <<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	}
	notify();
	(observerVector.at(0))->showStatus();
	ObserverForPlayers->showStatus();
}


void showTroopStatusAfterDeploy(vector<int> & inputControlList)
{
	if (inputControlList.size() == 0) return;

	for (auto iter = inputControlList.begin(); iter != inputControlList.end(); ++iter)
	{
		std::cout << "Region " << (*iter) << " , active solider number: " << ptPlayersMap->getRegion(*iter)->get_solider_current_race() <<
			" and   declined solider number: " << ptPlayersMap->getRegion(*iter)->get_solider_declined_race() << std::endl;
	}
}

int Players::normalBonusCount()
{
	controlledRegionList.shrink_to_fit();
	turnRegionConquerList.shrink_to_fit();
	return (static_cast<int>(controlledRegionList.size()) + static_cast<int>(turnRegionConquerList.size()));
}

void Players::BonusCount()
{
	int tempBonusCount = normalBonusCount() + ((this->get_current_race()) ? this->get_current_race()->specialRegionBonusCount() : 0) + ((this->get_current_power()) ? this->get_current_power()->specialRegionBounsCountTurnEnd() : 0);

	for (int i = 0; i < tempBonusCount; i++)
	{
		coin_1++;
		coin1--;
		if (coin1 < 0) std::cout << "System error! coin1 NOT enough " << std::endl;
		exchangeCoin();
	}
}


void Players::add_coin_1()
{

	coin_1++; 
	coin1--;
	exchangeCoin();

}

void Players::reduce_coin_1() 
{
	coin_1--;
	coin1++;
	exchangeCoin();
}


void Players::exchangeCoin()

{

	if ((coin_1 < 5)&&(coin_1 >= 0)) return;



	int tempTotalAmount = this->get_coin_1() + this->get_coin_3() * 3 + this->get_coin_5() * 5 + this->get_coin_10() * 10;



	coin1 += this->get_coin_1();

	coin3 += this->get_coin_3();

	coin5 += this->get_coin_5();

	coin10 += this->get_coin_10();



	this->set_coin_10((tempTotalAmount / 10 > coin10) ? coin10 : (tempTotalAmount / 10));

	tempTotalAmount -= coin_10 * 10;

	coin10 -= coin_10;

	this->set_coin_5(tempTotalAmount / 5 > coin5 ? coin5 : (tempTotalAmount / 5));

	tempTotalAmount -= coin_5 * 5;

	coin5 -= coin_5;

	this->set_coin_3(tempTotalAmount / 3 > coin3 ? coin3 : (tempTotalAmount / 3));

	tempTotalAmount -= coin_3 * 3;

	coin3 -= coin_3;

	this->set_coin_1(tempTotalAmount);

	coin1 -= coin_1;



	if (coin1 <0)

	{

		std::cout << "System error! coin1 NOT enough! " << std::endl;

		system("pause");

		exit(0);

	}

}


void Players::normalAttack(int ID_Region, int solider_needed)
{
	set_program_status("Conquer some regions");
	notify();

	// please consider the Declined race attack
	ptPlayersMap->getRegion(ID_Region)->set_owner(this->get_id_player());
	ptPlayersMap->getRegion(ID_Region)->set_cu_race_name(this->get_current_race()->getRaceName());
	ptPlayersMap->getRegion(ID_Region)->set_id_cu_race(this->get_current_race()->get_id_race());
	ptPlayersMap->getRegion(ID_Region)->set_solider_current_race(solider_needed);
	ptPlayersMap->getRegion(ID_Region)->set_de_race_name("");
	ptPlayersMap->getRegion(ID_Region)->set_id_de_race(-1);
	ptPlayersMap->getRegion(ID_Region)->set_solider_declined_race(0);
	if ((this->get_current_race()->getRaceName() == static_cast<string>("Trolls")) &&(this->get_in_hand_troll_lairs() > 0))
	{
		this->set_in_hand_troll_lairs(this->get_in_hand_troll_lairs() - 1);
		ptPlayersMap->getRegion(ID_Region)->set_troll_lairs_count(1);
	}

	this->set_in_hand_solider_current_race(this->get_in_hand_solider_current_race() - solider_needed);
	this->addTurnRegionConquerList(ID_Region);

	ptPlayersMap->getRegion(ID_Region)->printRegion();

	updateAdjacentRegionID();

	update_active_race_control_region_list();
	update_declined_race_control_region_list();
	notify();
	(observerVector.at(0))->showStatus();
	ObserverForPlayers->showStatus();
	showDomination();
}

vector<int> Players::getAvailableAttackRegion() //not the first time
{
	vector<int>  tempAdjRegionIDVector;

	if (this->get_current_race()->getRaceName() == (static_cast<string>("Halfings")))
	{
		for (int i = 0; i < ptPlayersMap->getNumRegion(); i++)
		{
			if (ptPlayersMap->getRegion(i)->get_cu_race_name() != (static_cast<string>("Halfings")))
			tempAdjRegionIDVector.push_back(i);
		}
		return tempAdjRegionIDVector;
	}

	if (this->get_current_power()->getbadgesName() == (static_cast<string>("Flying")))
	{
		for (int i = 0; i < ptPlayersMap->getNumRegion(); i++)
		{
			if ((ptPlayersMap->getRegion(i)->get_coastal_region_count() != 1) &&(ptPlayersMap->getRegion(i)->get_cu_race_name() != this->get_current_race()->getRaceName()))
				tempAdjRegionIDVector.push_back(i);
		}
		return tempAdjRegionIDVector;
	}
	if (adjacentRegionList.size() != 0)
		sort(adjacentRegionList.begin(), adjacentRegionList.end());
	return adjacentRegionList;
}

vector<int> Players::getFirstTimeAvailableAttackRegion()
{
	vector<int>  tempAdjRegionIDVector;

	if (this->get_current_race()->getRaceName() == (static_cast<string>("Halfings")))
	{
		for (int i = 0; i < ptPlayersMap->getNumRegion(); i++)
		{
			tempAdjRegionIDVector.push_back(i);
		}

		if (tempAdjRegionIDVector.size() != 0) sort(tempAdjRegionIDVector.begin(), tempAdjRegionIDVector.end());
		return tempAdjRegionIDVector;
	}

	if(this->get_current_power()->getbadgesName() == (static_cast<string>("Flying")))
	{
		for (int i = 0; i < ptPlayersMap->getNumRegion(); i++)
		{
			if (ptPlayersMap->getRegion(i)->get_coastal_region_count() != 1)
				tempAdjRegionIDVector.push_back(i);
		}
		if (tempAdjRegionIDVector.size() != 0) sort(tempAdjRegionIDVector.begin(), tempAdjRegionIDVector.end());
		return tempAdjRegionIDVector;
	}

	
		//int j = 0;
		/*ptPlayersMap->getRegion(21)->printRegion();
		cout << ptPlayersMap->getRegion(21)->get_is_at_boundary_of_map() << "-------";
		cout << ptPlayersMap->getRegion(21)->get_coastal_region_count() << endl;*/
		for (int i = 0; i < ptPlayersMap->getNumRegion(); i++) {


			if ((ptPlayersMap->getRegion(i)->get_is_at_boundary_of_map() == 1) && (ptPlayersMap->getRegion(i)->get_coastal_region_count() != 1)) {
				//j++;
				//cout << j << "  "<< i << endl;
	
				tempAdjRegionIDVector.push_back(i);
			}
			else if ((ptPlayersMap->getRegion(i)->get_is_at_boundary_of_map() == 1) && (ptPlayersMap->getRegion(i)->get_coastal_region_count() == 1) && (this->get_current_race()->getRaceName() == static_cast<string>("Seafaring")))
				tempAdjRegionIDVector.push_back(i);
			
		}
		if (tempAdjRegionIDVector.size() != 0) sort(tempAdjRegionIDVector.begin(), tempAdjRegionIDVector.end());
		//cout << "Region size return is " << tempAdjRegionIDVector.size() << endl; // test region vector size
		return tempAdjRegionIDVector;
	
}

 void printRegionList(vector<int> & inputVector)
{
	if (inputVector.size() == 0) return;

	//cout << inputVector.size() << endl; // input vector size wrong 

	for (auto iter = inputVector.begin(); iter != inputVector.end(); iter++)
	{
		std::cout << "    " << *iter << "   ";
	}
	std::cout << endl;
}

void Players::showAvailableAttackRegion(vector<int> & inputVector)
{
	vector<int>  tempRegionIDVector(inputVector);
	cout << "\nYou have " << this->get_in_hand_solider_current_race() << " tokens for this turn" << endl;
	std::cout << "\nThe current available regions for your attack are: " << endl;
	printRegionList(tempRegionIDVector);
}

int Players::getFirstTimeAttackRegionFromUser()
{
	vector<int> tempRegionIDVector(getFirstTimeAvailableAttackRegion());

	showAvailableAttackRegion(tempRegionIDVector);

	int userInputRegionID = -1;
	bool repeat = false;
	do
	{
		repeat = false;
		std::cout << "Please input the ID your desired region to attack which is from above available list. " << endl;

		if (pt_strategy_) userInputRegionID = pt_strategy_->strategyRegionSelection(this); // strategy for region selection
		else std::cin >> userInputRegionID;

		if (!containRegionID(&tempRegionIDVector, userInputRegionID))
		{
			repeat = true;
			std::cout << "The region ID you input is not in the current list , please check and input again. " << endl;
		}
	} while(repeat) ;

	return userInputRegionID;
}

int Players::getAttackRegionFromUser()
{
	vector<int>  tempRegionIDVector(getAvailableAttackRegion());

	showAvailableAttackRegion(tempRegionIDVector);

	int userInputRegionID = -1;
	bool repeat = false;
	do
	{
		repeat = false;
		std::cout << "Please input the ID your desired region to attack which is from above available list. " << endl;
		if (pt_strategy_) 
			userInputRegionID = pt_strategy_->strategyRegionSelection(this); // strategy for region selection
		else std::cin >> userInputRegionID;

		if (!containRegionID(&tempRegionIDVector, userInputRegionID))
		{
			repeat = true;
			std::cout << "The region ID you input is not in the current list , please check and input again. " << endl;
		}
	} while (repeat);

	return userInputRegionID;
}


int Players::normalConquerForceDemandCount(int ID_Region)

{

	int existingTroop = ptPlayersMap->getRegion(ID_Region)->get_solider_current_race() > ptPlayersMap->getRegion(ID_Region)->get_solider_declined_race() ? ptPlayersMap->getRegion(ID_Region)->get_solider_current_race() : ptPlayersMap->getRegion(ID_Region)->get_solider_declined_race();

	return (ptPlayersMap->getRegion(ID_Region)->get_mountain_count() + ptPlayersMap->getRegion(ID_Region)->get_lost_tribe_count() + 2 + existingTroop);

}




void Players::firstTurnAttack()
{
	update_game_turn();

	std::cout << " Player " << this->get_id_player() << " has " << this->get_in_hand_solider_current_race() << " solider in hand. " << std::endl;
	int attackRegionID = getFirstTimeAttackRegionFromUser();

	int neededTroopCountForSpecificRegion = normalConquerForceDemandCount(attackRegionID) +
		this->get_current_race()->conquerForceDemandCount(attackRegionID) +
		this->get_current_power()->conquerForceDemandCount(attackRegionID);

	if (neededTroopCountForSpecificRegion < 1) neededTroopCountForSpecificRegion = 1;

	//if (ptPlayersMap->getRegion(attackRegionID)->get_owner() != -1)
	//{
	//	Players* tempPlayer = ptPlayersPointerList->at(ptPlayersMap->getRegion(attackRegionID)->get_owner());
	//	tempPlayer->loseAndWithdraws(attackRegionID);
	//}
	//else 
		loseAndWithdraws(attackRegionID);

	this->get_current_race()->alternativeExchangeAttack(attackRegionID);
	this->get_current_power()->alternativeSpecialAttack(attackRegionID);
	normalAttack(attackRegionID, neededTroopCountForSpecificRegion);
	this->get_current_race()->afterAttackRetrealt();

	bool repeat = true;
	bool outerRepeat = true;
	int firstConqueredRegionID = -1;
	int secondConqueredRegionID = -1;
	int regionConquerCounter = 0;

	do
	{
		if ((this->get_in_hand_solider_current_race() == 0))
		{
			if (!((this->get_declined_race() != nullptr) && (this->get_declined_race()->getRaceName() == static_cast<string>("Ghouls")) && (this->get_in_hand_solider_declined_race() > 0)))
			{
				std::cout << "You do NOT have any solider in hand " << endl;
				break;
			}
		}

		regionConquerCounter++;

		do
		{
			repeat = true;
			attackRegionID = getAttackRegionFromUser();

			if (this->get_current_race()->getRaceName() == ptPlayersMap->getRegion(attackRegionID)->get_cu_race_name())
			{
				std::cout << "your input Region ID is your own region, please input a new valid Region ID!" << endl;
				repeat = true;
				continue;
			}
			if ((isAttckableRegion(attackRegionID)) && (this->get_current_race()->regionAttackAprove(attackRegionID)) && (this->get_current_power()->regionAttackAprove(attackRegionID))) repeat = false;
			else repeat = false;

		} while (repeat);

		neededTroopCountForSpecificRegion = normalConquerForceDemandCount(attackRegionID) +
			this->get_current_race()->conquerForceDemandCount(attackRegionID) + 
			this->get_current_power()->conquerForceDemandCount(attackRegionID);

		if (neededTroopCountForSpecificRegion < 1) neededTroopCountForSpecificRegion = 1;
		
		if ((this->get_in_hand_solider_current_race() > 0) && ((this->get_in_hand_solider_current_race()) >= neededTroopCountForSpecificRegion))
		{
			loseAndWithdraws(attackRegionID);
			this->get_current_race()->alternativeExchangeAttack(attackRegionID);
			this->get_current_power()->alternativeSpecialAttack(attackRegionID);
			normalAttack(attackRegionID, neededTroopCountForSpecificRegion);
			this->get_current_race()->afterAttackRetrealt();
			outerRepeat = true;
		}
		else if (this->get_in_hand_solider_current_race() == 0)
		{
			std::cout << "You now have 0 solider in hand! Not able to conquer any region." << std::endl;
			outerRepeat = false;
		}
		else 
		{
			std:cout << " This region demand at least " << neededTroopCountForSpecificRegion << " to conquer. " << endl;
			std::cout << " you have only " << this->get_in_hand_solider_current_race() << " soliders in hand." << endl;
			std::cout << "you have not enough soliders in hand, so a dice play is needed! " << endl;
			int tempDiceNumber = dice.rollingDice(true);

			if (this->get_in_hand_solider_current_race() + tempDiceNumber >= neededTroopCountForSpecificRegion)
			{
				loseAndWithdraws(attackRegionID);
				this->get_current_race()->alternativeExchangeAttack(attackRegionID);
				this->get_current_power()->alternativeSpecialAttack(attackRegionID);
				normalAttack(attackRegionID, this->get_in_hand_solider_current_race());
				this->get_current_race()->afterAttackRetrealt();
				cout << "\nAttack is done! Let's start deploy\n" << endl;
			}
			cout << "\noops! still not enough soliders, now you need to deploy.  \n" << endl;
			outerRepeat = false;
		}



		if (this->get_in_hand_solider_current_race() == 0) outerRepeat = false;
	} while (outerRepeat);
	
	this->get_current_race()->additionalDeploy();
	this->get_current_power()->specialDeployAfterAttack();
	this->get_current_race()->specialDeploy();
	this->normalDeploy();
	
		
	std::cout << "this is the end of the playing of player " << this->get_id_player() << " in this turn . " <<endl;
	std::cout << "\n****************************************************************************************************\n" << endl;
}


void Players::clearFormerDeclinedRaceSolider()
{
	for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
	{
		if ((ptPlayersMap->getRegion(i)->get_owner() == this->get_id_player()) && (ptPlayersMap->getRegion(i)->get_solider_declined_race() > 0))
		{
			if (containRegionID(&controlledRegionList, i)) removeControlledRegionID(i);
			if (containRegionID(&turnRegionConquerList, i)) removeTurnRegionConquerList(i);
			ptPlayersMap->getRegion(i)->set_troll_lairs_count(0);
			ptPlayersMap->getRegion(i)->set_fortresses_count(0);
			ptPlayersMap->getRegion(i)->set_encampments_count(0);
			ptPlayersMap->getRegion(i)->set_holes_in_the_ground_count(0);

			ptPlayersMap->getRegion(i)->set_owner(-1);
			ptPlayersMap->getRegion(i)->set_cu_race_name("");
			ptPlayersMap->getRegion(i)->set_de_race_name("");
			//ptPlayersMap->getRegion(i)->set_empty_region_count(1);
			ptPlayersMap->getRegion(i)->set_solider_current_race(0);
			ptPlayersMap->getRegion(i)->set_solider_declined_race(0);
			ptPlayersMap->getRegion(i)->set_id_cu_race(-1);
			ptPlayersMap->getRegion(i)->set_id_de_race(-1);
		}
	}
}

void Players::Decline()
{
	set_program_status("Decline status");
	notify();

	clearFormerDeclinedRaceSolider();

	if (this->get_current_race()->getRaceName() == static_cast<string>("Ghouls"))
	{
		for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
		{
			if (ptPlayersMap->getRegion(i)->get_owner() == this->get_id_player())
			{
				ptPlayersMap->getRegion(i)->set_de_race_name(ptPlayersMap->getRegion(i)->get_cu_race_name());
				ptPlayersMap->getRegion(i)->set_solider_declined_race(ptPlayersMap->getRegion(i)->get_solider_current_race());
				ptPlayersMap->getRegion(i)->set_cu_race_name("");
				ptPlayersMap->getRegion(i)->set_solider_current_race(0);
				ptPlayersMap->getRegion(i)->set_id_de_race(ptPlayersMap->getRegion(i)->get_id_cu_race());
				ptPlayersMap->getRegion(i)->set_id_cu_race(-1);
				
				ptPlayersMap->getRegion(i)->set_troll_lairs_count(0);
				ptPlayersMap->getRegion(i)->set_fortresses_count(0);
				ptPlayersMap->getRegion(i)->set_encampments_count(0);
				ptPlayersMap->getRegion(i)->set_holes_in_the_ground_count(0);
				ptPlayersMap->getRegion(i)->set_heroes_count(0);
				ptPlayersMap->getRegion(i)->set_dragon_count(0);

			}
		}
		this->set_in_hand_solider_declined_race(this->get_in_hand_solider_current_race());
	}
	else
	{
		
		for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
		{
			if (ptPlayersMap->getRegion(i)->get_owner() == this->get_id_player())
			{
				ptPlayersMap->getRegion(i)->set_de_race_name(ptPlayersMap->getRegion(i)->get_cu_race_name());
				ptPlayersMap->getRegion(i)->set_solider_declined_race(1);
				ptPlayersMap->getRegion(i)->set_cu_race_name("");
				ptPlayersMap->getRegion(i)->set_solider_current_race(0);
				ptPlayersMap->getRegion(i)->set_id_de_race(ptPlayersMap->getRegion(i)->get_id_cu_race());
				ptPlayersMap->getRegion(i)->set_id_cu_race(-1);

				if (this->get_current_race()->getRaceName() != static_cast<string>("Trolls")) 
					ptPlayersMap->getRegion(i)->set_troll_lairs_count(0);
				ptPlayersMap->getRegion(i)->set_fortresses_count(0);
				ptPlayersMap->getRegion(i)->set_encampments_count(0);
				ptPlayersMap->getRegion(i)->set_holes_in_the_ground_count(0);
				ptPlayersMap->getRegion(i)->set_heroes_count(0);
				ptPlayersMap->getRegion(i)->set_dragon_count(0);
			}
		}
		this->set_in_hand_solider_declined_race(0);//
	}
	
	this->set_in_hand_solider_current_race(0);
	this->set_declined_race(this->get_current_race());
	this->set_current_race(nullptr);
	this->set_current_power(nullptr);

	this->set_in_hand_troll_lairs(0);
	this->set_in_hand_fortresses(0);
	this->set_in_hand_encampments(0);
	this->set_in_hand_hole_in_the_ground(0);
	this->set_in_handhero(0);
	this->set_in_hand_dragon(0);

	pick_race();

	update_active_race_control_region_list();
	update_declined_race_control_region_list();
	notify();
	(observerVector.at(0))->showStatus();
	ObserverForPlayers->showStatus();
}

void Players::followingTurnAttack()  //******************************************************************************************************************************************
{
	update_game_turn();

	int userInputInt1 = -1;
	std::cout << "Do you need to declined immediately?  please input 1(yes) or 0(no) : " << endl;
	if (pt_strategy_) userInputInt1 = pt_strategy_->strategyDeclineDecision(this);  // strategy input
	else std::cin >> userInputInt1;

	if (userInputInt1)
	{
		this->Decline();
		return;
	}


	readyTroop();
	std::cout << " Player " << this->get_id_player() << " has " << this->get_in_hand_solider_current_race() << " solider in hand. " << std::endl;
	
	if ((this->get_declined_race()) &&(this->get_declined_race()->getRaceName() == static_cast<string>("Ghouls")))
		this->get_declined_race()->readyDeclinedTroop();

	abandonAreas();

	int attackRegionID = -100;
	int neededTroopCountForSpecificRegion = 0;
	bool repeat = true;
	bool outerRepeat = true;

	do
	{
		if ((this->get_in_hand_solider_current_race() == 0))
		{
			if (!((this->get_declined_race() != nullptr) && (this->get_declined_race()->getRaceName() == static_cast<string>("Ghouls")) && (this->get_in_hand_solider_declined_race() > 0)))
			{
				std::cout << "You do NOT have any solider in hand " << endl;
				break;
			}
		}


		do
		{
			repeat = true;
			attackRegionID = getAttackRegionFromUser();


			if (this->get_current_race()->getRaceName() == ptPlayersMap->getRegion(attackRegionID)->get_cu_race_name())
			{
				std::cout << "your input Region ID is your own region, please input a new valid Region ID!" << endl;
				repeat = true;
				continue;
			}
			else if ((isAttckableRegion(attackRegionID)) && (this->get_current_race()->regionAttackAprove(attackRegionID)) && (this->get_current_power()->regionAttackAprove(attackRegionID)))
				repeat = false;
			else
				repeat = true; // big change 

		} while (repeat);

		neededTroopCountForSpecificRegion = normalConquerForceDemandCount(attackRegionID) +
			this->get_current_race()->conquerForceDemandCount(attackRegionID) +
			this->get_current_power()->conquerForceDemandCount(attackRegionID);


		if ((this->get_in_hand_solider_current_race() > 0)&&((this->get_in_hand_solider_current_race()) >= neededTroopCountForSpecificRegion))
		{
			int beatenPlayer = -1;
			beatenPlayer = ptPlayersMap->getRegion(attackRegionID)->get_owner();
			if (beatenPlayer != -1)
			{
				if (ptPlayersPointerList->at(beatenPlayer)->get_current_race()->getRaceName() == static_cast<string>("Elves"))
				{
					ptPlayersPointerList->at(beatenPlayer)->get_current_race()->specialWithdraws(attackRegionID);
				}
				else
				{
					loseAndWithdraws(attackRegionID);
				}
			}
			else
			{
				loseAndWithdraws(attackRegionID);
			}

			this->get_current_race()->alternativeExchangeAttack(attackRegionID);
			this->get_current_power()->alternativeSpecialAttack(attackRegionID);
			normalAttack(attackRegionID, neededTroopCountForSpecificRegion);
			this->get_current_race()->afterAttackRetrealt();
			outerRepeat = true;
		}
		else if (this->get_in_hand_solider_current_race() == 0)
		{
		std::cout << "You now have 0 solider in hand! Not able to conquer any region." << std::endl;
			outerRepeat = false;
		}
		else
		{
			std::cout << " This region demand at least " << neededTroopCountForSpecificRegion << " to conquer. " << endl;
			std::cout << " you have only " << this->get_in_hand_solider_current_race() << " soliders in hand." << endl;
			std::cout << "you have not enough soliders in hand, so a dice play is needed! " << endl;
			int tempDiceNumber = dice.rollingDice(true);

			if (this->get_in_hand_solider_current_race() + tempDiceNumber >= neededTroopCountForSpecificRegion)
			{

				int beatenPlayer = -1;
				beatenPlayer = ptPlayersMap->getRegion(attackRegionID)->get_owner();

				if (beatenPlayer != -1)
				{
					if (ptPlayersPointerList->at(beatenPlayer)->get_current_race()->getRaceName() == static_cast<string>("Elves"))
					{
						ptPlayersPointerList->at(beatenPlayer)->get_current_race()->specialWithdraws(attackRegionID);
					}
					else
					{
						loseAndWithdraws(attackRegionID);
					}
				}
				else
				{
					loseAndWithdraws(attackRegionID);
				}

				this->get_current_race()->alternativeExchangeAttack(attackRegionID);
				this->get_current_power()->alternativeSpecialAttack(attackRegionID);
				normalAttack(attackRegionID, this->get_in_hand_solider_current_race());
				this->get_current_race()->afterAttackRetrealt();
				for (auto iter = observerVector.begin(); iter != observerVector.end(); ++iter)
				{
					if ((*iter)->get_observer_name() == static_cast<string>("playerDominationObserverDecorator"))
					{
						(*iter)->showStatus();
					}
				}
				cout << "\nAttack is done! Let's start deploy\n" << endl;
			}
			else std::cout << "oops, Soliders form dice are still not enough! you need  to redeploy now ." << std::endl;
			outerRepeat = false;
		}

		if (this->get_in_hand_solider_current_race() == 0) outerRepeat = false;

	} while (outerRepeat);
	
	
	this->get_current_race()->additionalDeploy();
	this->get_current_power()->specialDeployAfterAttack();
	this->get_current_race()->specialDeploy();
	this->normalDeploy();

	if (this->get_current_race()->getRaceName() == static_cast<string>("Stout"))
	{
		int userInputInt = -1;
		std::cout << "Do you need to declined immediately?  please input 1(yes) or 0(no) : " << endl;
		if (pt_strategy_) userInputInt = pt_strategy_->strategyDeclineDecision(this);  // strategy input
		else std::cin >> userInputInt;

		if (userInputInt)
		{
			this->Decline();
			
			BonusCount();

			int tempTotalAmount = this->get_coin_1() + this->get_coin_3() * 3 + this->get_coin_5() * 5 + this->get_coin_10() * 10;

			std::cout << "After this turn, Player " << this->ID_player << " have " << tempTotalAmount << " coins." << endl;

			set_already_counted_bouns(true);
		}
	}
}


void Players::readyTroop()
{
	for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
	{
		if ((ptPlayersMap->getRegion(i)->get_owner() == this->get_id_player())&&(ptPlayersMap->getRegion(i)->get_solider_current_race() > 1))
			this->set_in_hand_solider_current_race(this->get_in_hand_solider_current_race() + returnCurrentRaceTroop(i));
 	}
}

int Players::returnCurrentRaceTroop(int ID_Region)
{
	if (ptPlayersMap->getRegion(ID_Region)->get_solider_current_race() > 1)
	{
		int returnCurrentRaceSolider = ptPlayersMap->getRegion(ID_Region)->get_solider_current_race()-1;
		ptPlayersMap->getRegion(ID_Region)->set_solider_current_race(1);
		return returnCurrentRaceSolider;
	}
	return 0;
}

void Players::abandonAreas()
{
	set_program_status("Abandon some Areas");
	notify();

	int userInputInt = -1;
	std::cout << "Do you need to abandon some areas ?  please input 1(yes) or 0(no) : " << endl;
	std::cin >> userInputInt;

	if (userInputInt)
	{
		if (controlledRegionList.size() == 0)
		{
			std::cout << " you have no area to abandon! " << endl;
			return;
		}

		for (auto iter = controlledRegionList.begin(); iter != controlledRegionList.end(); )
		{
			Region * tempRegion = ptPlayersMap->getRegion(*iter);

			if (tempRegion->get_owner() == this->get_id_player())
			{
				std::cout << "Would you abandon Region " << (*iter) << " 1(yes) or 0(no) ? " << endl;

				int userInputRegionID = -1;

				std::cin >> userInputRegionID;

				if (static_cast<int>(userInputRegionID))
				{
					this->set_in_hand_solider_current_race(this->get_in_hand_solider_current_race() + ptPlayersMap->getRegion(*iter)->get_solider_current_race());
					ptPlayersMap->getRegion(*iter)->set_solider_current_race(0);
					this->set_in_hand_solider_declined_race(this->get_in_hand_solider_declined_race() + ptPlayersMap->getRegion(*iter)->get_solider_declined_race());
					ptPlayersMap->getRegion(*iter)->set_solider_declined_race(0);
					ptPlayersMap->getRegion(*iter)->set_cu_race_name("");
					ptPlayersMap->getRegion(*iter)->set_id_cu_race(-1);
					ptPlayersMap->getRegion(*iter)->set_de_race_name("");
					ptPlayersMap->getRegion(*iter)->set_id_de_race(-1);
					ptPlayersMap->getRegion(*iter)->set_owner(-1);
					this->set_in_hand_encampments(this->get_in_hand_encampments() + ptPlayersMap->getRegion(*iter)->get_encampments_count());
					ptPlayersMap->getRegion(*iter)->set_encampments_count(0);
					this->set_in_hand_fortresses(this->get_in_hand_fortresses() + ptPlayersMap->getRegion(*iter)->get_fortresses_count());
					ptPlayersMap->getRegion(*iter)->set_fortresses_count(0);
					this->set_in_hand_troll_lairs(this->get_in_hand_troll_lairs() + ptPlayersMap->getRegion(*iter)->get_troll_lairs_count());
					ptPlayersMap->getRegion(*iter)->set_troll_lairs_count(0);
					this->set_in_hand_hole_in_the_ground(this->get_in_hand_hole_in_the_ground() + ptPlayersMap->getRegion(*iter)->get_holes_in_the_ground_count());
					ptPlayersMap->getRegion(*iter)->set_holes_in_the_ground_count(0);
					this->set_in_hand_dragon(this->get_in_hand_dragon() + ptPlayersMap->getRegion(*iter)->get_dragon_count());
					ptPlayersMap->getRegion(*iter)->set_dragon_count(0);
					this->set_in_handhero(this->get_in_handhero() + ptPlayersMap->getRegion(*iter)->get_heroes_count());
					ptPlayersMap->getRegion(*iter)->set_heroes_count(0);

					iter = controlledRegionList.erase(iter);
				}
				else ++iter;
			}
			else ++iter;
		}
		controlledRegionList.shrink_to_fit();

		update_active_race_control_region_list();
		update_declined_race_control_region_list();
		notify();
		(observerVector.at(0))->showStatus();
		ObserverForPlayers->showStatus();

	}
	else return;
}

void Players::scoringVictoryCoins()
{
	set_program_status("Scores some victory coins");
	notify();

	if (!get_already_counted_bouns())
	{
		BonusCount();
	}

	int tempTotalAmount = this->get_coin_1() + this->get_coin_3() * 3 + this->get_coin_5() * 5 + this->get_coin_10() * 10;

	set_player_total_coins(tempTotalAmount);

	//std::cout << "After this turn, Player " << this->ID_player << " have " << tempTotalAmount << " coins." << endl;

	controlledRegionList.insert(controlledRegionList.end(), turnRegionConquerList.begin(), turnRegionConquerList.end());
	if (controlledRegionList.size() != 0) sort(controlledRegionList.begin(), controlledRegionList.end());
	turnRegionConquerList.clear();
	turnRegionConquerList.shrink_to_fit();
	set_already_counted_bouns(false);

	notify();
	(observerVector.at(0))->showStatus();
	ObserverForPlayers->showStatus();

	for (auto iter = observerVector.begin(); iter != observerVector.end(); ++iter)
	{
		if ((*iter)->get_observer_name() == static_cast<string>("victoryCoinsObserverDecorator"))
		{
			(*iter)->showStatus();
		}
	}
}

void showPlayersAtTurnEnd()
{
	std::cout << "****************************************************************************************************\n" << endl;
	
	for(auto iter = ptPlayersPointerList->begin(); iter != ptPlayersPointerList->end(); ++iter)
	{
		std::cout << "After this turn, Player " << (*iter)->get_id_player() << " control Region : ";
		vector<int> tempVector((*iter)->get_controlled_region_list());
		printRegionList(tempVector);
		std::cout << "\n"<< std::endl;

		if ((*iter)->get_current_race() != nullptr)
		{
			int totalActiveSolider = 0;
			int totalDeclinedSolider = 0;
			for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
			{
				if (ptPlayersMap->getRegion(i)->get_owner() == (*iter)->get_id_player())
				{
					totalActiveSolider += ptPlayersMap->getRegion(i)->get_solider_current_race();
					totalDeclinedSolider += ptPlayersMap->getRegion(i)->get_solider_declined_race();
				}
					
					//std::cout << "Region " << i << " has " << ptPlayersMap->getRegion(i)->get_solider_declined_race() << " declined soliders " << std::endl;
			}

			std::cout << "You currently has " << totalActiveSolider << " active race soliders in defending and ";
			totalActiveSolider += (*iter)->get_in_hand_solider_current_race();
			std::cout << (*iter)->get_in_hand_solider_current_race() << " soliders in hand. " << "In total " << totalActiveSolider << " soliders in active status. \n" << std::endl;

			if (totalDeclinedSolider > 0)
			{
				std::cout << "You currently has " << totalDeclinedSolider << " declined race soliders in defending and ";
				totalActiveSolider += (*iter)->get_in_hand_solider_declined_race();
				std::cout << (*iter)->get_in_hand_solider_declined_race() << " declined soliders in hand. " << "In total " << totalDeclinedSolider << " soliders in declined status. \n" << std::endl;

			}
		}
		
		/*if ((*iter)->get_declined_race() != nullptr)
		{
			int totalSolider = 0;
			for (int i = 0; i < ptPlayersMap->getNumRegion(); ++i)
			{
				if (ptPlayersMap->getRegion(i)->get_owner() == (*iter)->get_id_player())
					totalSolider += ptPlayersMap->getRegion(i)->get_solider_declined_race();
			} 

			std::cout << "currently has " << totalSolider << " soliders in defending and ";
			totalSolider += (*iter)->get_in_hand_solider_declined_race();
			std::cout << (*iter)->get_in_hand_solider_declined_race() << " soliders in hand. " << "In total " << totalSolider << " soliders in active status. " << std::endl;
		}*/

	}
	std::cout << "****************************************************************************************************\n" << endl;
}

void Players::attach(Observer * inputObserver)
{
	observerVector.push_back(inputObserver);
}

bool Players::containObserver(Observer * inputObserver)
{
	if (!(inputObserver))
	{
		std::cout << "inputObserver pointer is null void Players::detach(Observer * inputObserver)" << endl;
		system("pause");
		return false;
	}

	if (observerVector.size() != 0)
	{
		for (auto iter = observerVector.begin(); iter != observerVector.end(); ++iter)
		{
			if ((*iter) == inputObserver) 
			return true;
		}
	}
	return false;
}

void Players::detach(Observer * inputObserver)
{
	if(!(inputObserver))
	{
		std::cout << "inputObserver pointer is null void Players::detach(Observer * inputObserver)" << endl;
		system("pause");
		return;
	}
	for (auto iter = observerVector.begin(); iter != observerVector.end(); )
	{
		if ((*iter) == inputObserver) iter = observerVector.erase(iter);
		else ++iter;
	}
}

void Players::notify()
{
	for (auto iter = observerVector.begin(); iter != observerVector.end(); ++iter)
	{
		(*iter)->update(this);
	}
}

void Players::update_active_race_control_region_list()
{
	for (int regionID = 0; regionID != ptPlayersMap->getNumRegion(); regionID++)
	{
		if (ptPlayersMap->getRegion(regionID)->get_owner() == get_id_player())
		{
			if ((ptPlayersMap->getRegion(regionID)->get_solider_current_race() > 0) &&
				(ptPlayersMap->getRegion(regionID)->get_solider_declined_race() == 0))
				activeRaceControlRegionList.push_back(regionID);
		}
	}
}

void Players::update_declined_race_control_region_list()
{
	for (int regionID = 0; regionID != ptPlayersMap->getNumRegion(); regionID++)
	{
		if (ptPlayersMap->getRegion(regionID)->get_owner() == get_id_player())
		{
			if ((ptPlayersMap->getRegion(regionID)->get_solider_current_race() == 0) &&
				(ptPlayersMap->getRegion(regionID)->get_solider_declined_race() > 0))
				declinedRaceControlRegionList.push_back(regionID);
		}
	}
}

void Players::update_game_turn()
{
	set_Game_Turn_Marker(get_game_turn_marker() + 1);
}

void Players::showInHand()
{
	if (observerVector.size() == 0) return;
	for (auto iter = observerVector.begin(); iter != observerVector.end(); ++iter)
	{
		if ((*iter)->get_observer_name() == static_cast<string>("playerHandsObserverDecorator"))
		{
			(*iter)->showStatus();
		}
	}
}

void Players::showDomination()
{
	if (observerVector.size() == 0) return;
	for (auto iter = observerVector.begin(); iter != observerVector.end(); ++iter)
	{
		if ((*iter)->get_observer_name() == static_cast<string>("playerDominationObserverDecorator"))
		{
			(*iter)->showStatus();
		}
	}
}

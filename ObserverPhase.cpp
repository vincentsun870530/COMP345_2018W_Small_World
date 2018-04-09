#include "ObserverPhase.h"
#include "Players.h"
#include "Region.h"

ObserverPhase::ObserverPhase()
{
	set_observer_name("ObserverPhase");
}


ObserverPhase::~ObserverPhase()
{
}

void ObserverPhase::update(Players * inputPlayer)
{
	programStatus = inputPlayer->get_program_status();
	currentPlayerID = inputPlayer->get_id_player();
	currentInHandActiveRaceSolider = inputPlayer->get_in_hand_solider_current_race();
	currentInHandDeclinedRaceSolider = inputPlayer->get_in_hand_solider_declined_race();
	if (inputPlayer->get_current_race()) activeRaceName = inputPlayer->get_current_race()->getRaceName();
	if (inputPlayer->get_current_power()) activePowerName = inputPlayer->get_current_power()->getbadgesName();
	if ((inputPlayer->get_declined_race())) declinedRaceName = inputPlayer->get_declined_race()->getRaceName();
	currentControlRegionList = inputPlayer->get_controlled_region_list();
	turnConquerRegionList = inputPlayer->get_turn_region_conquer_list();
	adjacentRegionList = inputPlayer->get_adjacent_region_list();
	activeRaceControlRegionList = inputPlayer->get_active_race_control_region_list();
	declinedRaceControlRegionList = inputPlayer->get_declined_race_control_region_list();
	playerTotalCoins = inputPlayer->get_player_total_coins();
}


void ObserverPhase::update(Region * inputRegion)
{
	
}

void ObserverPhase::showStatus()
{

	std::cout << "\n\n************************************************************" << endl;
	std::cout << "Player " << currentPlayerID << " " << programStatus << "\n" << endl;

	if (programStatus == static_cast<string>("Scores some victory coins"))
	{
		std::cout << "Currently " << "player " << currentPlayerID << " has " << playerTotalCoins << " coins. " << endl;
	}
	else if (programStatus == static_cast<string>("Player pick a race"))
	{
		std::cout << "Currently " << "player " << currentPlayerID << " active race is  " << activeRaceName << endl;
		std::cout << "It has a special power of " << activePowerName << endl;
	}
	else if (programStatus == static_cast<string>("Player loss and withdraws"))
	{

	}
	else if (programStatus == static_cast<string>("Player deploy"))
	{
		showTroopStatusAfterDeploy(currentControlRegionList);
		showTroopStatusAfterDeploy(turnConquerRegionList);
	}
	else if (programStatus == static_cast<string>("Conquer some regions"))
	{
		showTroopStatusAfterDeploy(turnConquerRegionList);
	}
	else if (programStatus == static_cast<string>("Decline status"))
	{
		showTroopStatusAfterDeploy(activeRaceControlRegionList);
		showTroopStatusAfterDeploy(declinedRaceControlRegionList);
	}
	else if (programStatus == static_cast<string>("Abandon some Areas"))
	{
		showTroopStatusAfterDeploy(currentControlRegionList);
	}
	else;
	
	std::cout << "\n************************************************************\n\n" << endl;

}

#include "playerHandsObserverDecorator.h"
#include "Players.h"
#include "Map.h"

extern vector<Players *> * ptPlayersPointerList;
extern Map * ptPlayersMap;


playerHandsObserverDecorator::playerHandsObserverDecorator()
{
	set_observer_name("playerHandsObserverDecorator");
}


playerHandsObserverDecorator::~playerHandsObserverDecorator()
{
}

playerHandsObserverDecorator::playerHandsObserverDecorator(Observer * inputObserver) : ObserverDecorator(inputObserver)
{
	set_observer_name("playerHandsObserverDecorator");
	int numPlayers = static_cast<int>(ptPlayersPointerList->size());
	playerInHandCurrentRaceSoliderVector.resize(numPlayers);
	playerInHandDeclinedRaceSoliderVector.resize(numPlayers);
	playerInHandDragonVector.resize(numPlayers);
	playerInHandEncampmentsVector.resize(numPlayers);
	playerInHandFortressesVector.resize(numPlayers);
	playerInHandHeroesVector.resize(numPlayers);
	playerInHandHolesInTheGroundVector.resize(numPlayers);
	playerInHandTrollLairsVector.resize(numPlayers);

	for (int i = 0; i < numPlayers; ++i)
	{
		playerInHandCurrentRaceSoliderVector.at(i) = 0;
		playerInHandDeclinedRaceSoliderVector.at(i) = 0;
		playerInHandDragonVector.at(i) = 0;
		playerInHandEncampmentsVector.at(i) = 0;
		playerInHandFortressesVector.at(i) = 0;
		playerInHandHeroesVector.at(i) = 0;
		playerInHandHolesInTheGroundVector.at(i) = 0;
		playerInHandTrollLairsVector.at(i) = 0;
	}
}

void playerHandsObserverDecorator::update(Players* inputPlayer)
{
	ObserverDecorator::update(inputPlayer);

	int playerID = static_cast<int>(inputPlayer->get_id_player());

	playerInHandCurrentRaceSoliderVector.at(playerID) = inputPlayer->get_in_hand_solider_current_race();
	playerInHandDeclinedRaceSoliderVector.at(playerID) = inputPlayer->get_in_hand_solider_declined_race();
	playerInHandDragonVector.at(playerID) = inputPlayer->get_in_hand_dragon();
	playerInHandEncampmentsVector.at(playerID) = inputPlayer->get_in_hand_encampments();
	playerInHandFortressesVector.at(playerID) = inputPlayer->get_in_hand_fortresses();
	playerInHandHeroesVector.at(playerID) = inputPlayer->get_in_handhero();
	playerInHandHolesInTheGroundVector.at(playerID) = inputPlayer->get_in_hand_hole_in_the_ground();
	playerInHandTrollLairsVector.at(playerID) = inputPlayer->get_in_hand_troll_lairs();
}
void playerHandsObserverDecorator::update(Region* inputRegion)
{
	return;
}
void playerHandsObserverDecorator::showStatus()
{
	std::cout << "\n****************************************************************************************************\n" << endl;

	std::cout << "\nView of Player Hands Observer Decorator \n" << endl;

	ObserverDecorator::showStatus();

	int numPlayers = static_cast<int>(ptPlayersPointerList->size());

	for (int i = 0; i < numPlayers; ++i)
	{
		std::cout << "Player " << i << " have " << playerInHandCurrentRaceSoliderVector.at(i) << " active race soliders in hand" << endl;
		std::cout << "Player " << i << " have " << playerInHandDeclinedRaceSoliderVector.at(i) << " declined race soliders in hand" << endl;
		std::cout << "Player " << i << " have " << playerInHandDragonVector.at(i) << " Dragon badge in hand" << endl;
		std::cout << "Player " << i << " have " << playerInHandEncampmentsVector.at(i) << " Encampments in hand" << endl;
		std::cout << "Player " << i << " have " << playerInHandFortressesVector.at(i) << " Fortresses in hand" << endl;
		std::cout << "Player " << i << " have " << playerInHandHolesInTheGroundVector.at(i) << " Holes_in_the_ground in hand" << endl;
		std::cout << "Player " << i << " have " << playerInHandTrollLairsVector.at(i) << " Troll Lairs in hand" << endl;
	}

	std::cout << "\n****************************************************************************************************\n" << endl;
}
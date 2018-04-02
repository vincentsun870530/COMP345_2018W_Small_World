#include "startupPhase.h"
#include <algorithm>
#include "GamePieces/Encampments.h"
#include "GamePieces/LairFromTroll.h"
#include "GamePieces/TwoHolesInTheGround.h"
#include "GamePieces/Fortesses.h"
#include "GamePieces/Mountains.h"
#include "GamePieces/Dragon.h"
#include "GamePieces/Heroes.h"


extern int coin1;
extern int coin3;
extern int coin5;
extern int coin10;
extern int gameTurnMarker = 0;
extern vector<Players *> * ptPlayersPointerList;
std::vector<GamePiece *> * gamePieceVector = nullptr;
std::vector<RaceBanner *> * raceBannerVector = nullptr;
std::vector<Badges *> * specialPowerBadgesVector = nullptr;

startupPhase::startupPhase()
{
}


startupPhase::~startupPhase()
{
}

void startupPhase::setGamePieceVector() // Set Game Piece Vector
{
	std::vector<GamePiece *> * tempGamePieceVector(new std::vector<GamePiece*>);

	tempGamePieceVector->push_back(new Encampments());
	tempGamePieceVector->push_back(new LairFromTroll());
	tempGamePieceVector->push_back(new TwoHolesInTheGround());
	tempGamePieceVector->push_back(new Fortesses());
	tempGamePieceVector->push_back(new Mountains());
	tempGamePieceVector->push_back(new Dragon());
	tempGamePieceVector->push_back(new Heroes());

	gamePieceVector = tempGamePieceVector;

	printGamePieceVector();

}

void printGamePieceVector() // Print game piece name and amount
{
	if (gamePieceVector)
	{
		for (auto p = gamePieceVector->begin(); p != gamePieceVector->end(); p++)
		{
			std::cout << (*p)->getName() << " " << (*p)->getTokenCost() << std::endl;
		}
	}
}


void startupPhase::setGameTurnMarker()
{
	gameTurnMarker = 0;
}

void startupPhase::setRaceBannerVector()
{
	std::vector<RaceBanner *> * tempRaceBannerVector(new std::vector<RaceBanner*>);

	tempRaceBannerVector->push_back(new Amazons());
	tempRaceBannerVector->push_back(new Dwarves());
	tempRaceBannerVector->push_back(new Elves());
	tempRaceBannerVector->push_back(new Ghouls());
	tempRaceBannerVector->push_back(new Ratmen());
	tempRaceBannerVector->push_back(new Skeletons());
	tempRaceBannerVector->push_back(new Sorceres());
	tempRaceBannerVector->push_back(new Tritons());
	tempRaceBannerVector->push_back(new Giants());
	tempRaceBannerVector->push_back(new Halflings());
	tempRaceBannerVector->push_back(new Humans());
	tempRaceBannerVector->push_back(new Orcs());
	tempRaceBannerVector->push_back(new Trolls());
	tempRaceBannerVector->push_back(new Wizards());
	
	raceBannerVector = tempRaceBannerVector;

	printRaceBannerVector();
}

void startupPhase::setSpecialPowerBadgesVector()
{
	std::vector<Badges *> * tempSpecialPowerBadgesVector = (new std::vector<Badges *>);

	tempSpecialPowerBadgesVector->push_back(new Alchemist());
	tempSpecialPowerBadgesVector->push_back(new Berserk());
	tempSpecialPowerBadgesVector->push_back(new Bivouacking());
	tempSpecialPowerBadgesVector->push_back(new Commando());
	tempSpecialPowerBadgesVector->push_back(new Diplomat());
	tempSpecialPowerBadgesVector->push_back(new DragonMaster());
	tempSpecialPowerBadgesVector->push_back(new Flying());
	tempSpecialPowerBadgesVector->push_back(new Forest());
	tempSpecialPowerBadgesVector->push_back(new Fortified());
	tempSpecialPowerBadgesVector->push_back(new Heroic());
	tempSpecialPowerBadgesVector->push_back(new Hill());
	tempSpecialPowerBadgesVector->push_back(new Merchant());
	tempSpecialPowerBadgesVector->push_back(new Mounted());
	tempSpecialPowerBadgesVector->push_back(new Pillaging());
	tempSpecialPowerBadgesVector->push_back(new Seafaring());
	tempSpecialPowerBadgesVector->push_back(new Spirit());
	tempSpecialPowerBadgesVector->push_back(new Stout());
	tempSpecialPowerBadgesVector->push_back(new Swamp());
	tempSpecialPowerBadgesVector->push_back(new Underworld());
	tempSpecialPowerBadgesVector->push_back(new Wealthy());
	
	specialPowerBadgesVector = tempSpecialPowerBadgesVector;

	printSpecialPowerBadgesVector();

};

void startupPhase::bannersShuffling()
{
	if (raceBannerVector)
	{
		std::random_shuffle((*raceBannerVector).begin(), (*raceBannerVector).end());

		int indexNumberOfRaceBanners = 0;
		for (auto p = (*raceBannerVector).begin(); p != (*raceBannerVector).end(); ++p)
		{
			(*p)->set_id_race(indexNumberOfRaceBanners++);
		}
	}

	printRaceBannerVector();
	
	/*if (raceBannerVector)
	{
		std::vector<int> * v = shuffling(14);
		std::vector<RaceBanner *> * tempRaceBannerVector = nullptr;
		for (int i = 0; i < 14; i++)
		{
			tempRaceBannerVector->push_back(raceBannerVector->at((v->at(i))));
		}
		raceBannerVector->clear();
		raceBannerVector = tempRaceBannerVector;
		v->clear();
		v = nullptr;
	}*/

}


void startupPhase::badgesShuffling()
{
	if (specialPowerBadgesVector)
	{
		std::random_shuffle((*specialPowerBadgesVector).begin(), (*specialPowerBadgesVector).end());

		int indexNumberOfSpecialPowerBadges = 0;
		for (auto p = (*specialPowerBadgesVector).begin(); p != (*specialPowerBadgesVector).end(); ++p)
		{
			(*p)->set_id_badges(indexNumberOfSpecialPowerBadges++);
		}
	}
	
	printSpecialPowerBadgesVector();

	/*if(specialPowerBadgesVector)
	{
		std::vector<int> * v = shuffling(20);
		std::vector<Badges *> * tempSpecialPowerBadges = nullptr;
		for (int i = 0; i < 20; i++)
		{
			tempSpecialPowerBadges->push_back(specialPowerBadgesVector->at((v->at(i))));
		}
		specialPowerBadgesVector->clear();
		specialPowerBadgesVector = tempSpecialPowerBadges;
		v->clear();
		v = nullptr;
	}*/
}



//
//std::vector<int> * startupPhase::shuffling(int size)
//{
//	std::vector<int> *  v( new std::vector<int>);
//
//	for (int i = 0; i < size; ++i) {
//		(*v).push_back(i);
//	}
//
//	std::random_shuffle((*v).begin(), (*v).end());
//
//	return v;
//}



void startupPhase::setPlayersCoin()
{
	if(ptPlayersPointerList)
	{
		for (vector<Players *> ::iterator p = (*ptPlayersPointerList).begin(); p != (*ptPlayersPointerList).end(); ++p)
		{
			for (int i = 0; i < 5; i++)
			{
				(*p)->add_coin_1();
			}
		}
	}

	printPlayersList();
}


//void startupPhase::test()
//{
//	
//	std::vector<int> *  v = startupPhase::shuffling(14);
//	for (int k = 0; k < 14; ++k)
//	{
//		std::cout << "array[" << k << "] = " << v->at(k) << std::endl;
//	}
//	std::vector<int> *  v1(new std::vector<int>);
//	for (int i = 0; i < 14; ++i)
//	{
//		v1->push_back(v->at(i));
//	}
//	
//	for (int k = 0; k < 14; ++k)
//	{
//		std::cout << "array[" << k << "] = " << v1->at(k) << std::endl;
//	}
//
//}


void printRaceBannerVector()
{
	if(raceBannerVector)
	{
		for(auto p = raceBannerVector->begin() ; p != raceBannerVector->end(); p++)
		{
			std::cout << "Race " << (*p)->get_id_race() << " : " << (*p)->getRaceName() << std::endl;
		}
	}
}

void printSpecialPowerBadgesVector()
{
	if (specialPowerBadgesVector)
	{
		for (auto p = specialPowerBadgesVector->begin(); p != specialPowerBadgesVector->end(); p++)
		{
			std::cout << "Special Power " << (*p)->get_id_badges() << " : " << (*p)->getbadgesName() << std::endl;
			//std::cout << (*p)->getSpecialPowerName() << std::endl;
		}
	}
}

void printPlayersList()
{
	if (ptPlayersPointerList)
	{
		for (auto p = ptPlayersPointerList->begin(); p != ptPlayersPointerList->end(); p++)
		{
			std::cout << "Player  " << (*p)->get_id_player() << " : " << " Has "; 
			(*p)->printCoins();
		}
	}
}
#pragma once
#include "RaceBanner/RaceBanner.h"
#include "RaceBanner/Amazons.h"
#include "RaceBanner/Dwarves.h"
#include "RaceBanner/LostTribes.h"
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
#include "Badges/Badges.h"
#include "Badges/Alchemist.h"
#include "Badges/Berserk.h"
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
#include <vector>
#include "Players.h"


extern int gameTurnMarker;

void printGamePieceVector(); // Print Game Piece Vector
void printRaceBannerVector();
void printSpecialPowerBadgesVector();
void printPlayersList();

class startupPhase
{
public:
	startupPhase();
	~startupPhase();

	void setGamePieceVector(); // Set Game Piece Vector

	void setGameTurnMarker();

	void setRaceBannerVector();

	void setSpecialPowerBadgesVector();

	void bannersShuffling();

	void badgesShuffling();

	//std::vector<int> * shuffling(int size);
	
	void setPlayersCoin();

	//void test();
};


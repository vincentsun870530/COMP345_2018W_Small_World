#include "pickupRacePower.h"

extern  vector<Players *> * ptPlayersPointerList;
extern std::vector<RaceBanner *> * raceBannerVector;
extern std::vector<Badges *> * specialPowerBadgesVector;

int get_correct_inputNumberOfChoice(int i, int k) // globle function
{
	int inputNumber = -1;
	bool inputIsNotCorrect;
	do {
		try {
			inputIsNotCorrect = false;
			cout << "Please input number from between  " << i << " and " << k << " " << endl;
			cin >> inputNumber;
			if((inputNumber < i) || (inputNumber > k))
			{
				throw runtime_error("Exception input should be a number and >=" + to_string(i) + " or <=" + to_string(k));
			}
		}catch(runtime_error& ex)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.what() << endl;
			inputIsNotCorrect = true;
		}
		
	} while (inputIsNotCorrect);

	return inputNumber;
}


int currentMaxNumberOfRace() // globle function
{
	int availableCount = 0;
	int vectorIndex = 0;
	int max = -1;
	for (auto iter = raceBannerVector->begin(); (iter != raceBannerVector->end()); iter++)
	{
		if ((*iter)->is_available()) { availableCount++; max = vectorIndex; };
		if (availableCount == 5)  break;
		vectorIndex++;
	}
	return max;
}


int getNumberInputForRace() // globle function
{
	bool repeat = true;
	int NumberInputForRace = -1;

	int MaxNumberOfAvailableRace = currentMaxNumberOfRace();

	if (MaxNumberOfAvailableRace < 0)
	{
		return MaxNumberOfAvailableRace;
	}

	do
	{
		NumberInputForRace = get_correct_inputNumberOfChoice(0, 13);

		//cout << " ((raceBannerVector->at(NumberInputForRace))->is_available()) " << ((raceBannerVector->at(NumberInputForRace))->is_available()) << endl;
		//cout << "  (NumberInputForRace <= MaxNumberOfAvailableRace)) " << NumberInputForRace << " < " << MaxNumberOfAvailableRace << endl;

		try {
			
			if(((raceBannerVector->at(NumberInputForRace))->is_available()) && (NumberInputForRace <= MaxNumberOfAvailableRace))
			{
			repeat = false;
			}
			else
			{
			throw runtime_error( "Exception Your option is not available! Please select your desired race again! ") ;
		
			}
		}catch(runtime_error& ex)
		{
			cout<<ex.what()<<endl;
			repeat = true;
		}
	} while (repeat);
	return NumberInputForRace;
}

void showALLRacesBadges() // for test4
{


	if (raceBannerVector)
	{
		int i = 0;

		cout << "For Testing 14 combos. All race and badges combo are :" << endl;
		for (auto iter = raceBannerVector->begin(); (iter != raceBannerVector->end()); ++iter)
		{
			if ((*iter)->is_available())
			{
				std::cout << "Race " << (*iter)->get_id_race() << " : " << (*iter)->getRaceName() << "   " << " Badges " << (specialPowerBadgesVector->at(i))->get_id_badges() << " : " << ((specialPowerBadgesVector->at(i)))->getbadgesName() << endl;
				i++;
			}
		}
	}
	else std::cout << "there is no available races and badges now! " << std::endl;
}

void showAllRacesBadges() //global function
{
	if (raceBannerVector)
	{
		for (auto iter = raceBannerVector->begin(); (iter != raceBannerVector->end()); ++iter)
		{
			std::cout << "Race " << (*iter)->get_id_race() << " " << (*iter)->getRaceName() << " available " <<(*iter)->is_available() <<endl;
		}
	}

	if (specialPowerBadgesVector)
	{
		for (auto iter = specialPowerBadgesVector->begin(); (iter != specialPowerBadgesVector->end()); ++iter)
		{
			std::cout << "Special power " << (*iter)->get_id_badges() << " " << (*iter)->getbadgesName() << " available " << (*iter)->is_available() << endl;
		}
	}
}

void show6OrLessAvailableRacesBadges() // globle function
{
	if (raceBannerVector)
	{
		int i = 0, j = 0;
		for (auto iter = raceBannerVector->begin(); (iter != raceBannerVector->end())&&(i < 6); ++iter)
		{
			if ((*iter)->is_available())
			{
				std::cout << "Race " << (*iter)->get_id_race() << " : " << (*iter)->getRaceName() <<"   " << " Badges " << (specialPowerBadgesVector->at(j))->get_id_badges() << " : " << ((specialPowerBadgesVector->at(j)))->getbadgesName() << endl;
				i++;
			}
			j++;
		}
	}
	else std::cout << "there is no available races and badges now! " << std::endl;
}


void pickupRacePower::action()
{
	int availableNumberOfRaceBadges = -1;

	for (auto playerIter = (*ptPlayersPointerList).begin(); playerIter != (*ptPlayersPointerList).end(); playerIter++)
	{
		std::cout << "Please input the desired race and badge number: " << endl;
		availableNumberOfRaceBadges = getNumberInputForRace();
		(*playerIter)->pick_race(availableNumberOfRaceBadges);
	}
};


pickupRacePower::pickupRacePower()
{
}


pickupRacePower::~pickupRacePower()
{
}



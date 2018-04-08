#include "Region.h"
#include <iostream>
#include <boost/serialization/vector.hpp>



Region::Region()
{
	//std::cout <<  " a new Region is created! " << std::endl;
}

Region::~Region()
{
}

bool Region::is_is_region_change() const
{
	return isRegionChange;
}

void Region::set_is_region_change(bool is_region_change)
{
	isRegionChange = is_region_change;
}

void Region::printRegion() {
	std::cout << "\nRegion ID: " << get_region_id() << std::endl;
	std::cout << "Current ruling race:  " << get_cu_race_name() << std::endl;
	std::cout << "Current owner:  " << get_owner() << std::endl;
	std::cout << "Number of soldiers of current region ruling race:  " << get_solider_current_race() << std::endl;
	std::cout << "Number of soldiers of declined race: " << get_solider_declined_race() << std::endl;
	std::cout << "Region characteristic " << get_region_char() << std::endl;
	std::cout << "Declined race:  " << deRaceName << std::endl;
	std::cout << "This region is still controlled by a lost tribe:   " << static_cast<bool>(get_lost_tribe_count()) << " \n "<< std::endl;
}


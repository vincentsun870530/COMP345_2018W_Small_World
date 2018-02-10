#include "Map.h"
#include "Region.h"
#include <iostream>
#include <stdbool.h>

using namespace std;

int main() {

	Map *map1 =  new Map(5,true);

	cout << "this map is connected? " << boolalpha <<(*map1).isConnected() << endl;

	//auto p1 = (*map1).RetadjListRegions(1)->begin;
	//auto p1 = (*map1).RetadjListRegions(1)->end;

	for (int i = 0; i < 5; ++i) {
		
	}

	delete map1;
	map1 = nullptr;

	system("pause");

}
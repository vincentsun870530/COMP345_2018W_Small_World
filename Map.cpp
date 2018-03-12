#include "Map.h"
#include "Region.h"
#include <iostream> 
#include <utility> 
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>
#include <vector>
#include <string>
#include <stdbool.h>

using namespace std;
using namespace boost;

//typedef adjacency_list<setS, vecS, undirectedS > Graph;
//typedef graph_traits<Graph>::vertex_iterator vertex_iter;
//typedef graph_traits<Graph>::adjacency_iterator adjVertex_iter;


Map::Map()
{
	//Map::numVertces = 1;
	////gra(1) = new Graph(1);
	//add_vertex(gra);
	//Map::initRegionVector(1);
}

Map::Map(int n)
{
	Map::numVertces = n;
	for (int i = 0; i < n; ++i) {
		add_vertex(gra);
	};
	//gra = new Graph(numVertces);
	Map::initRegionVector(n);
}

Map::Map(int n, bool dft) {
	Map::numVertces = n;
	for (int i = 0; i < n; ++i) {
		add_vertex(gra);
	};
	//gra = new Graph(n);
	add_edge(0, 1, gra);
	add_edge(0, 5, gra);
	add_edge(1, 2, gra);
	add_edge(1, 5, gra);
	add_edge(1, 6, gra);
	add_edge(2, 3, gra);
	add_edge(2, 6, gra);
	add_edge(2, 7, gra);
	add_edge(2, 8, gra);
	add_edge(3, 4, gra);
	add_edge(3, 8, gra);
	add_edge(3, 9, gra);
	add_edge(4, 9, gra);
	add_edge(4, 10, gra);
	add_edge(5, 6, gra);
	add_edge(5, 11, gra);
	add_edge(6, 7, gra);
	add_edge(6, 11, gra);
	add_edge(6, 12, gra);
	add_edge(7, 8, gra);
	add_edge(7, 12, gra);
	add_edge(7, 13, gra);
	add_edge(8, 9, gra);
	add_edge(8, 13, gra);
	add_edge(8, 14, gra);
	add_edge(9, 10, gra);
	add_edge(9, 14, gra);
	add_edge(10, 14, gra);
	add_edge(10, 15, gra);
	add_edge(11, 12, gra);
	add_edge(11, 16, gra);
	add_edge(11, 17, gra);
	add_edge(11, 12, gra);
	add_edge(12, 13, gra);
	add_edge(12, 17, gra);
	add_edge(12, 18, gra);
	add_edge(13, 14, gra);
	add_edge(13, 18, gra);
	add_edge(13, 19, gra);
	add_edge(13, 20, gra);
	add_edge(14, 15, gra);
	add_edge(14, 20, gra);
	add_edge(14, 21, gra);
	add_edge(15, 21, gra);
	add_edge(15, 22, gra);
	add_edge(16, 17, gra);
	add_edge(17, 18, gra);
	add_edge(18, 19, gra);
	add_edge(19, 20, gra);
	add_edge(20, 21, gra);
	add_edge(20, 22, gra);
	add_edge(21, 22, gra);
	add_edge(20, 21, gra);

	add_edge(3, 5, gra);
	add_edge(3, 14, gra);
	add_edge(3, 17, gra);
	add_edge(5, 14, gra);
	add_edge(14, 17, gra);

	add_edge(15, 20, gra);
	add_edge(2, 12, gra);
	add_edge(2, 13, gra);
	add_edge(6, 8, gra);
	add_edge(6, 13, gra);
	add_edge(8, 12, gra);

	Map::initRegionVector(n);

	getRegion(0)->set_adjacent_mountain_count(1);
	getRegion(0)->set_coastal_region_count(1);
	getRegion(0)->set_is_at_boundary_of_map(1);
	getRegion(1)->set_farmland_count(1);
	getRegion(1)->set_magic_region_count(1);
	getRegion(2)->set_forest_region_count(1);
	getRegion(2)->set_mine_region_count(1);
	getRegion(3)->set_swamp_region_count(1);
	getRegion(3)->set_lost_tribe_count(1);
	getRegion(3)->set_cavern_region_count(1);
	getRegion(4)->set_farmland_count(1);
	getRegion(5)->set_mountain_count(1);
	getRegion(5)->set_cavern_region_count(1);
	getRegion(5)->set_mine_region_count(1);
	getRegion(6)->set_farmland_count(1);
	getRegion(6)->set_lost_tribe_count(1);
	getRegion(7)->set_coastal_region_count(1);
	getRegion(8)->set_mountain_count(1);
	getRegion(9)->set_farmland_count(1);
	getRegion(10)->set_forest_region_count(1);
	getRegion(10)->set_magic_region_count(1);
	getRegion(10)->set_mine_region_count(1);
	getRegion(11)->set_farmland_count(1);
	getRegion(11)->set_lost_tribe_count(1);
	getRegion(12)->set_forest_region_count(1);
	getRegion(12)->set_lost_tribe_count(1);
	getRegion(13)->set_farmland_count(1);
	getRegion(13)->set_lost_tribe_count(1);
	getRegion(13)->set_magic_region_count(1);
	getRegion(14)->set_farmland_count(1);
	getRegion(14)->set_lost_tribe_count(1);
	getRegion(15)->set_mountain_count(1);
	getRegion(15)->set_mine_region_count(1);
	getRegion(16)->set_swamp_region_count(1);
	getRegion(16)->set_magic_region_count(1);
	getRegion(16)->set_lost_tribe_count(1);
	getRegion(17)->set_farmland_count(1);
	getRegion(17)->set_cavern_region_count(1);
	getRegion(18)->set_swamp_region_count(1);
	getRegion(18)->set_lost_tribe_count(1);
	getRegion(18)->set_mine_region_count(1);
	getRegion(19)->set_mountain_count(1);
	getRegion(20)->set_swamp_region_count(1);
	getRegion(21)->set_forest_region_count(1);
	getRegion(22)->set_coastal_region_count(1);

	getRegion(0)->set_is_at_boundary_of_map(1);
	getRegion(1)->set_is_at_boundary_of_map(1);
	getRegion(2)->set_is_at_boundary_of_map(1);
	getRegion(3)->set_is_at_boundary_of_map(1);
	getRegion(4)->set_is_at_boundary_of_map(1);
	getRegion(5)->set_is_at_boundary_of_map(1);
	getRegion(11)->set_is_at_boundary_of_map(1);
	getRegion(16)->set_is_at_boundary_of_map(1);
	getRegion(17)->set_is_at_boundary_of_map(1);
	getRegion(18)->set_is_at_boundary_of_map(1);
	getRegion(19)->set_is_at_boundary_of_map(1);
	getRegion(20)->set_is_at_boundary_of_map(1);
	getRegion(22)->set_is_at_boundary_of_map(1);
	getRegion(15)->set_is_at_boundary_of_map(1);
	getRegion(10)->set_is_at_boundary_of_map(1);

	getRegion(1)->set_adjacent_mountain_count(1);
	getRegion(6)->set_adjacent_mountain_count(1);
	getRegion(2)->set_adjacent_mountain_count(1);
	getRegion(3)->set_adjacent_mountain_count(1);
	getRegion(9)->set_adjacent_mountain_count(1);
	getRegion(14)->set_adjacent_mountain_count(1);
	getRegion(13)->set_adjacent_mountain_count(1);
	getRegion(7)->set_adjacent_mountain_count(1);
	getRegion(18)->set_adjacent_mountain_count(1);
	getRegion(20)->set_adjacent_mountain_count(1);
	getRegion(10)->set_adjacent_mountain_count(1);
	getRegion(21)->set_adjacent_mountain_count(1);
	getRegion(22)->set_adjacent_mountain_count(1);

}

void Map::ad_vertex() {
	add_vertex(gra);
}

void Map::ad_edge(int start, int end) {
	add_edge(start, end, gra);
}

bool Map::isConnected()
{
	vector<int> c(num_vertices(gra));
	int num = connected_components(gra, make_iterator_property_map(c.begin(), get(vertex_index, gra)));
	cout << "there are " << num_vertices(gra) << " vertices in this graph \n" << endl;
	cout << "there are " << num << " components in this graph \n" << endl;

	if (0 == num)
		cout << "the map is NOT valid, since this graph has No component. \n" << endl;
	else if (1 == num)
		cout << " The map is valid since it's graph has only one component. \n" << endl;
	else 
		cout << "the map is NOT valid, since this graph has more than one component. \n" << endl;

	return (1 == num);
}

void Map::initRegionVector(int n)
{
	
	for (int i = 0; i < n; ++i) {
		regList.push_back(new Region());
		(*(regList.at(i))).set_region_id(i);
	}
}

vector<int>* Map::retAdjRegionsNumList(int vertexID) {

	tempRegionNumList.clear();

	adjVertex_iter ait, aend;

	for (tie(ait, aend) =  adjacent_vertices(vertexID,gra); ait != aend; ++ait)
	{
		tempRegionNumList.push_back(*ait);
		//cout << "the added vertices into adjacet list is " << (*ait) << endl;
	}
	//cout << "finish " << endl;
	 
	return &tempRegionNumList;
}

void Map::printoutAdjRegionNumList(int vertexID) {

	//cout << "there are " << retAdjRegionsNumList(vertexID)->size() << " adjacent regions " << endl;
	//cout << " The adjacent nodes ID is below " << endl;
	for (unsigned int itt = 0; itt < retAdjRegionsNumList(vertexID)->size(); itt++) {
		cout << retAdjRegionsNumList(vertexID)->at(itt) << " ";
	}

	cout << endl;
}

void Map::printMap() {
	if (numVertces == 0) {
		cout << " This graph contain no regions currently! " << endl;
	}
	else {
		cout << " This graph currently has " << numVertces  << " regions! \n"<< endl;

		for (int i = 0; i < numVertces; i++) {
			cout << " Region " << i << " connectes region  ";
			printoutAdjRegionNumList(i);
		}

		cout << "\n" << endl;

		isConnected();
	}
}


Region* Map::getRegionPointer(int numRegion) 
{
	return regList[numRegion];

};

Region* Map::getRegion(int n)
{
	return (regList[n]);
};

vector<Region*> Map::getMountRegion() //get Mount List
{
	vector<Region*> tempMountRegList;

	for (auto p = regList.begin(); p != regList.end(); p++)
	{
		if ((*p)->get_mountain_count() == 1)
		{
			tempMountRegList.push_back(*p);
		}
	}

	return tempMountRegList;
};

void Map::printMountainPieceRegion() // print all mountain piece on map
{

	vector<Region*> tempMountRegList = getMountRegion();

	cout << "Mountain Gamepiece on map are " << endl;
	for (auto p = tempMountRegList.begin(); p != tempMountRegList.end(); p++)
	{
		cout << (*p)->get_region_id() + 1 << " ";
	}
	cout << endl;

};

void Map::printGamePieceRegion() // print all game piece on map
{


};




Map::~Map()
{

}

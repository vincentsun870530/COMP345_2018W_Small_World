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
	gra = new Graph(1);
	Map::initRegionVector(1);
}

Map::Map(int n)
{
	Map::numVertces = n;
	gra = new Graph(numVertces);
	Map::initRegionVector(n);
}

Map::Map(int n, bool dft) {
			Map::numVertces = n;
			gra = new Graph(n);
			add_edge(0, 1, *gra);
			add_edge(1, 2, *gra);
			add_edge(2, 3, *gra);
			add_edge(3, 4, *gra);
			Map::initRegionVector(n);

}

bool Map::isConnected()
{
	vector<int> c(num_vertices(*gra));
	int num = connected_components(*gra, make_iterator_property_map(c.begin(), get(vertex_index, *gra)));
	cout << "there are " << num << " components in this graph " << endl;
	return (1 == num);
}

void Map::initRegionVector(int n)
{
	
	for (int i = 0; i < n; ++i) {
		regList.push_back(new Region());
		(*(regList.at(i))).setRegionID(i);
	}
}

vector<Region*>* Map::RetadjListRegions(int  vertexID) {

	adjVertex_iter ait, aend;

	for (tie(ait, aend) =  adjacent_vertices(vertexID,*gra); ait != aend; ++ait)
	{
		tempRegionList.push_back(regList.at(*ait));
		
	}
	return &tempRegionList;
}

Map::~Map()
{

}
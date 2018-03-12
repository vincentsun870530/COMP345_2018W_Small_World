#pragma once

namespace boost {
	namespace serialization {
		class access;
	}
}

#include <vector>
#include "Region.h"
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/graph/adj_list_serialize.hpp>


using namespace std;
using namespace boost;

typedef adjacency_list<setS, vecS, undirectedS > Graph;
typedef graph_traits<Graph>::vertex_iterator vertex_iter;
typedef graph_traits<Graph>::adjacency_iterator adjVertex_iter;

class Map
{
public:
	
	Map();
	~Map();
	Map(int n);
	Map(int n, bool dft);
	bool isConnected();
	void initRegionVector(int n);
	vector<int>* retAdjRegionsNumList(int vertexID);
	void printoutAdjRegionNumList(int vertexID);
	vector<int> tempRegionNumList;
	Region* getRegionPointer(int numRegion);
	Region* getRegion(int n);
	vector<Region*> getMountRegion(); // getMountRegion ID
	void ad_vertex();
	void ad_edge(int start, int end);
	void printMap();
	void printMountainPieceRegion(); //print all mountain piece on map 
	void printGamePieceRegion(); // print all game piece on map
	int getNumRegion() { return numVertces; }
	
private:

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & numVertces;
		ar & regList;
		ar & gra;
	}

	int numVertces;
	vector<Region*> regList;
	Graph gra;
};

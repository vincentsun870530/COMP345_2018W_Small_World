#pragma once

#include <vector>
#include "Region.h"
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

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
	vector<Region*>* RetadjListRegions(int vertexID);
	vector<Region*> adjListRegions;
	vector<Region*>* pAdjListRegions = &adjListRegions;
	vector<Region*> tempRegionList;
	vector<Region*>* pTempRegionList = &tempRegionList;
	

private:
	int numVertces;
	vector<Region*> regList;
	Graph *gra;
};

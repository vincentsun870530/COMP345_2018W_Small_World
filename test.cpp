//#include <iostream> // for std::cout
//#include <utility> // for std::pair
//#include <boost/graph/graph_traits.hpp>
//#include <boost/graph/adjacency_list.hpp>
//#include <boost/graph/connected_components.hpp>
//#include <vector>
//#include <string>
//
//struct Region2 {
//	std::string name;
//	unsigned population;
//};
//
//using namespace boost;
//using namespace std;
//int main()
//{
//
//
//	Region2 v0, v1, v2, v3, v4, v5, v6;
//
//	v0 = { "shanghai" , 100 };
//	v1 = { "chengdu" , 200 };
//	v2 = { "congqing" , 300 };
//	v3 = { "xianggang" , 400 };
//	v4 = { "xinjiapo" , 500 };
//	v5 = { "taibei" , 600 };
//
//	vector<Region2>  regionVec;
//
//	regionVec.push_back(v0);
//	regionVec.push_back(v1);
//	regionVec.push_back(v2);
//	regionVec.push_back(v3);
//	regionVec.push_back(v4);
//	regionVec.push_back(v5);
//
//
//
//	typedef adjacency_list<listS, vecS, undirectedS > Graph;
//	Graph g;
//
//	/*add_edge(0, 1, g);
//	add_edge(1, 4, g);
//	add_edge(4, 0, g);
//	add_edge(2, 5, g);*/
//
//	add_edge(0, 1, g);
//	add_edge(1, 2, g);
//	add_edge(2, 3, g);
//	add_edge(3, 0, g);
//
//	typedef graph_traits<Graph>::vertex_iterator vertex_iter;
//	pair<vertex_iter, vertex_iter> vip;
//	cout << "Vertices in g  = [ ";
//	vip = vertices(g);
//	for (vertex_iter vi = vip.first; vi != vip.second; ++vi) {
//		cout << regionVec[(*vi)].name << "  \t" << regionVec[((int)(*vi))].population << endl;
//	}
//	cout << "]" << endl;
//
//	typedef graph_traits<Graph>::adjacency_iterator adjVertex_iter;
//
//
//
//	cout << "***********************************************************************" << endl;
//	adjVertex_iter ait, aend;
//	for (tie(ait, aend) = adjacent_vertices(3, g);
//		ait != aend; ++ait)
//		cout << *ait << endl;
//
//	system("pause");
//	return 0;
//}

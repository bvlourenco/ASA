#ifndef JOHNSON
#define JOHNSON

#include "Graph.hpp"
#include <queue>

/*Prototipes for Bellman-Ford functions*/
void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex);
void RelaxBellmanFord(vector<int> &dvalues, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue);
vector<int> algorithmBellmanFord(const Graph &g, int indexVertex);
/*Prototipes for Dijkstra functions*/
void initPriorityQueue(const vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, int numVertex);
void RelaxDijkstra(vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue);
vector<int> algorithmDijkstra(const Graph &g, int indexVertex);

void printValues(const vector<int> &dvalues, const vector<int> &pivalues, int numVertex);
void setValue(int value, int srcHeight, int destHeight);
void printJohnson(const vector<vector<int>> &allDvalues, int numVertex);
void algorithmJohnson(const Graph &g);

#endif
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.hpp"
#include <queue>

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex);
void initPriorityQueue(const vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, int numVertex);
void Relax(vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue);
void algorithmDijkstra(const Graph &g, int indexVertex);

#endif

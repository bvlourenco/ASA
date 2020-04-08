#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.hpp"
#include <queue>
/*0x3f3f3f3f is very big, so it can represent infinit (0xffffffff is the largest number but it can give overflow)*/
#define INFINIT 0x3f3f3f3f
#define NIL -1

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex);
void initPriorityQueue(const vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, int numVertex);
void Relax(vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue, int *i);
void printValues(const vector<int> &dvalues, const vector<int> &pivalues, int numVertex);
void algorithmDijkstra(const Graph &g, int indexVertex);

#endif

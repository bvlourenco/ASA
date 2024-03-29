#ifndef BELLMAN_FORD
#define BELLMAN_FORD

#include "Graph.hpp"
#define INFINIT 0x3f3f3f3f
#define NIL -1

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex);
void Relax(vector<int> &dvalues, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue);
void printValues(const vector<int> &dvalues, const vector<int> &pivalues, int numVertex);
bool algorithmBellmanFord(const Graph &g, int indexVertex);

#endif
#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <iostream>
#include <utility>

#define AdjLst vector<list<pair<int, int>>>

using namespace std;

class Graph {
    int V;
    AdjLst adjLst;
public:
    Graph(int V);
    void addEdge(int v1, int v2, int w);
    void printGraph();
    int getNumVertex() const;
    AdjLst getadjLst() const;
    ~Graph();
};

#endif

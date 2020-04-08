#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class Graph {
    int V;
    vector<list<pair<int, int>>> adjLst;
public:
    Graph(int V);
    Graph(const Graph &g);
    void addVertex();
    void removeVertex();
    void addEdge(int v1, int v2, int w);
    void printGraph();
    int getNumVertex() const;
    vector<list<pair<int, int>>> getadjLst() const;
    vector<list<pair<int, int>>>& getModifiableAdjLst();
    ~Graph();
};

#endif

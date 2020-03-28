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
    void addEdge(int v1, int v2, int w);
    void printGraph();
    int getNumVertex() const;
    vector<list<pair<int, int>>> getadjLst() const;
    ~Graph();
};

#endif

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Graph {
    int V;
    vector<list<int>> adjLst;
public:
    Graph(int V);
    void addEdge(int v1, int v2);
    void printGraph();
    int getNumVertex() const;
    ~Graph();
};

#endif

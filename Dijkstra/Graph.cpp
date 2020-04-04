#include "Graph.hpp"

Graph::Graph(int numVertex) : V(numVertex), adjLst(numVertex) {}

void Graph::addEdge(int v1, int v2, int w) {
    adjLst[v1].push_back(make_pair(v2, w));
}

void Graph::printGraph() {
    for(int i = 0; i < this->V; i++) {
        for(auto iterator = adjLst[i].begin(); iterator != adjLst[i].end(); iterator++) {
            cout << i << "-->" << iterator->first << " w:" << iterator->second << " | ";
        }
        cout << "\n";
    }
    cout << flush;
}

int Graph::getNumVertex() const {
    return this->V;
}

vector<list<pair<int, int>>> Graph::getadjLst() const {
    return this->adjLst;
}

Graph::~Graph() {
    //TBD if necessary
}
#include "Graph.hpp"

Graph::Graph(int numVertex) : V(numVertex), adjLst(numVertex) {}

Graph::Graph(const Graph &g) : V(g.V), adjLst(g.V) {
    for(int i = 0; i < V; i++) {
        for(auto iterator = g.adjLst[i].begin(); iterator != g.adjLst[i].end(); iterator++) {
            addEdge(i, iterator->first, iterator->second);
        }
    }
}

void Graph::addVertex() {
    adjLst.resize(V+1);
    this->V++;
}

void Graph::removeVertex() {
    adjLst.resize(V-1);
    this->V--;
}

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

AdjLst Graph::getadjLst() const {
    return this->adjLst;
}

AdjLst& Graph::getModifiableAdjLst() {
    return this->adjLst;
}

Graph::~Graph() {
    //TBD if necessary
}
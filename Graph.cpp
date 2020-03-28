#include "Graph.hpp"

Graph::Graph(int numVertex) : V(numVertex), adjLst(numVertex) {}

void Graph::addEdge(int v1, int v2) {
    adjLst[v1].push_back(v2);
}

void Graph::printGraph() {
    for(int i = 0; i < this->V; i++) {
        for(auto iterator = adjLst[i].begin(); iterator != adjLst[i].end(); iterator++) {
            cout << *iterator << " ";
        }
        cout << "\n";
    }
    cout << flush;
}

Graph::~Graph() {
    //TBD if necessary
}

int main() {
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.printGraph();
    return 0;
}
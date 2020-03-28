#include "Graph.hpp"

Graph::Graph(int numVertex) : V(numVertex), adjLst(numVertex) {}

void Graph::addEdge(int v1, int v2) {
    adjLst[v1].push_back(v2);
}

void Graph::printGraph() {
    for(int i = 0; i < this->V; i++) {
        for(auto iterator = adjLst[i].begin(); iterator != adjLst[i].end(); iterator++) {
            cout << i << "-->" << *iterator << " ";
        }
        cout << "\n";
    }
    cout << flush;
}

int Graph::getNumVertex() const {
    return this->V;
}

Graph::~Graph() {
    //TBD if necessary
}

int main() {
    int numVertex, numEdge, vin,vout;
    cin >> numVertex >> numEdge;
    Graph g(numVertex);
    while(numEdge) {
        cin >> vin >> vout;
        g.addEdge(vin, vout);
        numEdge--;
    }
    //TAKE THIS LINE BELOW!!!
    cout << "\n" << flush;
    g.printGraph();
    return 0;
}
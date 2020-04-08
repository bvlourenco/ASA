#include "Graph.hpp"
#include "Johnson.hpp"

int main() {
    int numVertex, numEdge, vin, vout, w;
    cin >> numVertex >> numEdge;
    Graph g(numVertex);
    while(numEdge) {
        cin >> vin >> vout >> w;
        g.addEdge(vin, vout, w);
        numEdge--;
    }
    //TAKE THIS LINE BELOW!!!
    cout << "\n" << flush;
    g.printGraph();
    algorithmJohnson(g);
    return 0;
}
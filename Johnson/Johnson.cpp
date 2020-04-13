#include "Johnson.hpp"

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex) {
    fill(dvalues.begin(), dvalues.end(), INFINIT);
    fill(pivalues.begin(), pivalues.end(), NIL);
    dvalues[indexVertex] = 0;
}

void RelaxBellmanFord(vector<int> &dvalues, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue) {
    if(vdvalue > u.second + v.second) {
        dvalues[v.first] = u.second + v.second;
        pivalues[v.first] = u.first;
    }
}

void printValues(const vector<int> &dvalues, const vector<int> &pivalues, int numVertex) {
    cout << "\nAfter Dijkstra algorithm: \n\nD values: \n";
    for(int i = 0; i < numVertex; i++) {
        cout << dvalues[i] << " | ";
    }
    cout << "\n\nPi values: \n";
    for(int i = 0; i < numVertex; i++) {
        cout << pivalues[i] << " | ";
    }
    cout << endl;
}

vector<int> algorithmBellmanFord(const Graph &g, int indexVertex) {
    int numVertex = g.getNumVertex();
    AdjLst adjLst = g.getadjLst();
    vector<int> dvalues(numVertex), pivalues(numVertex);
    InitializeSingleSource(dvalues, pivalues, indexVertex);
    for(int i = 0; i < numVertex - 1; i++) {
        for(int j = 0; j < numVertex; j++) {
            pair<int, int> u = make_pair(j, dvalues[j]);
            for(auto iterator = adjLst[j].begin(); iterator != adjLst[j].end(); iterator++) {
                RelaxBellmanFord(dvalues, pivalues, u, *iterator, dvalues[iterator->first]);
            }
        }
    }
    for(int i = 0; i < numVertex; i++) {
        pair<int, int> u = make_pair(i, dvalues[i]);
        for(auto iterator = adjLst[i].begin(); iterator != adjLst[i].end(); iterator++) {
            if(dvalues[iterator->first] > u.second + iterator->second) {
                cout << "\nGraph with negative cycle" << endl;
                dvalues[0] = -1;
                return dvalues;
            }
        }
    }
    printValues(dvalues, pivalues, numVertex);
    return dvalues;
}

void initPriorityQueue(const vector<int> &dvalues, priority_queue <pair<int, int>, vector<pair<int, int>>, GREATER> &Q, int numVertex) {
    for(int i = 0; i < numVertex; i++) {
        Q.push(make_pair(dvalues[i], i));
    }
}

void RelaxDijkstra(vector<int> &dvalues, priority_queue <pair<int, int>, vector<pair<int, int>>, GREATER> &Q, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue, int *i) {
    if(vdvalue > u.first + v.second) {
        dvalues[v.first] = u.first + v.second;
        pivalues[v.first] = u.second;
        Q.push(make_pair(dvalues[v.first], v.first));
        (*i)++;
    }
}

vector<int> algorithmDijkstra(const Graph &g, int indexVertex) {
    int numVertex = g.getNumVertex();
    int i = numVertex - 1;
    AdjLst adjLst = g.getadjLst();
    vector<int> dvalues(numVertex), pivalues(numVertex), isVisited(numVertex, NO);
    InitializeSingleSource(dvalues, pivalues, indexVertex);
    priority_queue <pair<int, int>, vector<pair<int, int>>, GREATER> Q;
    initPriorityQueue(dvalues, Q, numVertex);
    while(i > 0) {
        pair<int,int> u = Q.top();
        Q.pop();
        if(u.first == INFINIT) {
            break;
        }
        if(isVisited[u.second]) {
            continue;
        }
        isVisited[u.second] = YES;
        i--;
        for(auto iterator = adjLst[u.second].begin(); iterator != adjLst[u.second].end(); iterator++) {
            RelaxDijkstra(dvalues, Q, pivalues, u, *iterator, dvalues[iterator->first], &i);
        }
    }
    printValues(dvalues, pivalues, numVertex);
    return dvalues;
}

/*Check comments for Dijkstra and Bellman Ford in their respective folders*/

int setValue(int value, int srcHeight, int destHeight) {
    return value + srcHeight - destHeight;
}

void printJohnson(const vector<vector<int>> &allDvalues, int numVertex) {
    cout << "\nAfter Johnson algorithm: \n\nD values: \n";
    for(int i = 0; i < numVertex; i++) {
        for(int j = 0; j < numVertex; j++) {
            if (allDvalues[i][j] == INFINIT) {
                cout << "∞" << "|";
            } else {
                cout << allDvalues[i][j] << "|";
            }
        }
        cout << "\n";
    }
    cout << endl;
}

void algorithmJohnson(const Graph &g) {
    vector<int> dvalues;
    vector<vector<int>> allDvalues;
    int gVertex = g.getNumVertex();
    /*We make a new graph who is equal to original graph and add it a vertex s
     *We add edges from s to other vertex and the weight of those edges will be 0
     */
    Graph newGraph(g);
    newGraph.addVertex();
    for(int i = 0; i < gVertex; i++) {
        newGraph.addEdge(gVertex, i, 0);
    }
    /*We need a reference to adjacency list of new graph (that can be modifiable) to be able to change weight of edges*/
    AdjLst& adjLst = newGraph.getModifiableAdjLst();
    dvalues = algorithmBellmanFord(newGraph, gVertex);
    if (dvalues[0] != -1) {
        /*For every edge, we change weight of edge if appliable*/
        for(int j = 0; j <= gVertex; j++) {
            for(auto iterator = adjLst[j].begin(); iterator != adjLst[j].end(); iterator++) {
                iterator->second = setValue(iterator->second, dvalues[j], dvalues[iterator->first]);
            }
        }
        /*Now, we need original graph, so we remove extra vertex we added (and the edges coming from it)*/
        newGraph.removeVertex();
        newGraph.printGraph();
        /*We run Dijkstra in each vertex and put discover value in matrix using setValue function*/
        for(int i = 0; i < gVertex; i++) {
            allDvalues.push_back(algorithmDijkstra(newGraph, i));
            for(int j = 0; j < gVertex; j++) {
                if(allDvalues[i][j] != INFINIT) {
                    allDvalues[i][j] = setValue(allDvalues[i][j], dvalues[j], dvalues[i]);
                }
            }
        }
        printJohnson(allDvalues, gVertex);
    }
}
#include "BellmanFord.hpp"

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex) {
    fill(dvalues.begin(), dvalues.end(), 0x3f3f3f3f);
    fill(pivalues.begin(), pivalues.end(), -1);
    dvalues[indexVertex] = 0;
}

void Relax(vector<int> &dvalues, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue) {
    if(vdvalue > u.second + v.second) {
        dvalues[v.first] = u.second + v.second;
        pivalues[v.first] = u.first;
    }
}

void printValues(const vector<int> &dvalues, const vector<int> &pivalues, int numVertex) {
    cout << "\nAfter Bellman-Ford algorithm: \n\nD values: \n";
    for(int i = 0; i < numVertex; i++) {
        cout << dvalues[i] << " | ";
    }
    cout << "\n\nPi values: \n";
    for(int i = 0; i < numVertex; i++) {
        cout << pivalues[i] << " | ";
    }
    cout << endl;
}

bool algorithmBellmanFord(const Graph &g, int indexVertex) {
    int numVertex = g.getNumVertex();
    vector<list<pair<int, int>>> adjLst = g.getadjLst();
    vector<int> dvalues(numVertex), pivalues(numVertex);
    InitializeSingleSource(dvalues, pivalues, indexVertex);
    for(int i = 0; i < numVertex - 1; i++) {
        for(int j = 0; j < numVertex; j++) {
            pair<int, int> u = make_pair(j, dvalues[j]);
            for(auto iterator = adjLst[j].begin(); iterator != adjLst[j].end(); iterator++) {
                Relax(dvalues, pivalues, u, *iterator, dvalues[iterator->first]);
            }
        }
    }
    for(int i = 0; i < numVertex; i++) {
        pair<int, int> u = make_pair(i, dvalues[i]);
        for(auto iterator = adjLst[i].begin(); iterator != adjLst[i].end(); iterator++) {
            if(dvalues[iterator->first] > u.second + iterator->second) {
                cout << "\nGraph with negative cycle" << endl;
                return false;
            }
        }
    }
    printValues(dvalues, pivalues, numVertex);
    return true;
}
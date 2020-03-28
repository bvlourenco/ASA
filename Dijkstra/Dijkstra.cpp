#include "Dijkstra.hpp"

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex) {
    fill(dvalues.begin(), dvalues.end(), 0x3f3f3f3f);
    fill(pivalues.begin(), pivalues.end(), -1);
    dvalues[indexVertex] = 0;
}

void initPriorityQueue(const vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, int numVertex) {
    for(int i = 0; i < numVertex; i++) {
        Q.push(make_pair(i, dvalues[i]));
    }
}

void Relax(vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue) {
    if(vdvalue > u.second + v.second) {
        dvalues[v.first] = u.second + v.second;
        pivalues[v.first] = u.first;
        /*We cant do decrease key operation on std::priority queue so we insert a new element in the heap with key decreased. Complexity is the same O(logV)*/
        Q.push(make_pair(v.first, dvalues[v.first]));
    }
}

void algorithmDijkstra(const Graph &g, int indexVertex) {
    int i = 0;
    int numVertex = g.getNumVertex();
    vector<list<pair<int, int>>> adjLst = g.getadjLst();
    vector<int> dvalues(numVertex), pivalues(numVertex);
    InitializeSingleSource(dvalues, pivalues, indexVertex);
    priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    initPriorityQueue(dvalues, Q, numVertex);
    /*To ensure that we visit the V entries of queue with the lowest key so that complexity of Dijkstra stays O(ElogV)*/
    while(!Q.empty() && i < numVertex) {
        pair<int,int> u = Q.top();
        Q.pop();
        for(auto iterator = adjLst[u.first].begin(); iterator != adjLst[u.first].end(); iterator++) {
            Relax(dvalues, Q, pivalues, u, *iterator, dvalues[iterator->first]);
        }
        i++;
    }
    cout << "After Dijkstra algorithm: ";
    for(int i = 0; i < numVertex; i++) {
        cout << dvalues[i] << " | ";
    }
    cout << "\n";
    for(int i = 0; i < numVertex; i++) {
        cout << pivalues[i] << " | ";
    }
    cout << endl;
}
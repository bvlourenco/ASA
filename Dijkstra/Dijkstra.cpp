#include "Dijkstra.hpp"

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex) {
    /*0x3f3f3f3f represents infinit*/
    fill(dvalues.begin(), dvalues.end(), 0x3f3f3f3f);
    /*-1 represents nil*/
    fill(pivalues.begin(), pivalues.end(), -1);
    dvalues[indexVertex] = 0;
}

void initPriorityQueue(const vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, int numVertex) {
    for(int i = 0; i < numVertex; i++) {
        Q.push(make_pair(dvalues[i], i));
    }
}

void Relax(vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue) {
    if(vdvalue > u.first + v.second) {
        dvalues[v.first] = u.first + v.second;
        pivalues[v.first] = u.second;
        /*We cant do decrease key operation on std::priority queue so we insert a new element in the heap with key decreased. Complexity is the same O(logV)*/
        Q.push(make_pair(dvalues[v.first], v.first));
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

void algorithmDijkstra(const Graph &g, int indexVertex) {
    int i = 0;
    int numVertex = g.getNumVertex();
    vector<list<pair<int, int>>> adjLst = g.getadjLst();
    vector<int> dvalues(numVertex), pivalues(numVertex);
    InitializeSingleSource(dvalues, pivalues, indexVertex);
    /*To make a min priority queue, we can use regular priority queue with greater comparator (default comparator makes a max heap)*/
    priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    initPriorityQueue(dvalues, Q, numVertex);
    /*To ensure that we visit the V entries of queue with the lowest key so that complexity of Dijkstra stays O(ElogV)*/
    while(i < numVertex) {
        pair<int,int> u = Q.top();
        Q.pop();
        /*If discovery time for a given vertex is infinity, we don't need to relax it*/
        if(u.first == 0x3f3f3f3f) {
            break;
        }
        for(auto iterator = adjLst[u.second].begin(); iterator != adjLst[u.second].end(); iterator++) {
            Relax(dvalues, Q, pivalues, u, *iterator, dvalues[iterator->first]);
        }
        i++;
    }
    printValues(dvalues, pivalues, numVertex);
}
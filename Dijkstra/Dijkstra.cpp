#include "Dijkstra.hpp"

void InitializeSingleSource(vector<int> &dvalues, vector<int> &pivalues, int indexVertex) {
    fill(dvalues.begin(), dvalues.end(), INFINIT);
    fill(pivalues.begin(), pivalues.end(), NIL);
    dvalues[indexVertex] = 0;
}

void initPriorityQueue(const vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, int numVertex) {
    for(int i = 0; i < numVertex; i++) {
        Q.push(make_pair(dvalues[i], i));
    }
}

void Relax(vector<int> &dvalues, priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> &Q, vector<int> &pivalues, pair<int,int> u, pair<int,int> v, int vdvalue, int *i) {
    if(vdvalue > u.first + v.second) {
        dvalues[v.first] = u.first + v.second;
        pivalues[v.first] = u.second;
        /*We cant do decrease key operation on std::priority queue so we insert a new element in the heap with key decreased. Complexity is the same O(logV)*/
        Q.push(make_pair(dvalues[v.first], v.first));
        (*i)++;
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
    int numVertex = g.getNumVertex();
    int i = numVertex - 1;
    vector<list<pair<int, int>>> adjLst = g.getadjLst();
    vector<int> dvalues(numVertex), pivalues(numVertex);
    InitializeSingleSource(dvalues, pivalues, indexVertex);
    /*To make a min priority queue, we can use regular priority queue with greater comparator (default comparator makes a max heap)*/
    priority_queue <int, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    initPriorityQueue(dvalues, Q, numVertex);
    /*Since we have old elements on std::priority queue, we have to have a counter i that counts the first k number
     *of elements in priority queue (the remaining ones are old elements)
     */
    while(i > 0) {
        pair<int,int> u = Q.top();
        Q.pop();
        i--;
        /*If minimum discovery time of the vertex in priority queue is infinite, we can stop the algorithm
         *(we don't delete values from priority queue --(hence)--> this is a measure to otimize the algorithm)
         */
        if(u.first == INFINIT) {
            break;
        }
        for(auto iterator = adjLst[u.second].begin(); iterator != adjLst[u.second].end(); iterator++) {
            Relax(dvalues, Q, pivalues, u, *iterator, dvalues[iterator->first], &i);
        }
    }
    printValues(dvalues, pivalues, numVertex);
}
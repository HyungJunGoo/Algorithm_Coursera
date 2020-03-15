#include <iostream>
#include <list>
#include <stack>


using namespace std;

class Graph
{
    int V; // # of vertices
    list<int>* adj; // An array of adjacency lists

    void fillOrder(int v, bool visited[], stack<int> &Stack);

    public:
        Graph(int V);

        void addEdge(int v, int w);

        
};
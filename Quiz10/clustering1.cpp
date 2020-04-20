#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;


class Graph
{
    int V;
    vector<pi>* adj;
    
public:
    Graph(int V);
    void addEdge(int v, int w, int edge);
    void initGroup(int V, vector<int> group);
    void clustering(int start);
    int get_min_pair();
    int get_max_spacing();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<pi>[V+1];
    
}

void Graph::addEdge(int v, int w, int edge)
{
    adj[v].push_back(make_pair(w, edge));
    adj[w].push_back(make_pair(v, edge));
}

bool sortbysec(const pi &a, const pi &b)
{
    return a.second < b.second;
}

void Graph::initGroup(int V, vector<int> group)
{
    for (int i = 1; i <= V; i++)
        group[i] = i; // initialise group 
}

int main()
{
    fstream file;
    file.open("clustering1.txt");
    int V; // # of vertices
    file >> V;
    
    vector<pi> adj(V);
    Graph g(V);
    while (file.peek() != EOF)
    {
        int v, x, edge;
        file >> v >> x >> edge;
        g.addEdge(v, x, edge);
    }
    vector<int> group (V+1);
    g.initGroup(V, group);
    int num_of_group = V;

    return 0;
}
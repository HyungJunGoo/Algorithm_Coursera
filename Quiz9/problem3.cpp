#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
#define INF INT_MAX
class Graph
{
    int V; // # of vertices
    vector<pi>* adj;
    vector<bool> Selected;
    vector<pi> edges;
    int total_cost;
public:
    Graph(int V);
    void init_MST(int MST[]);
    void addEdge(int v, int w, int cost);
    int primMST(int src);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<pi>[V+1];
    Selected = vector<bool> (V+1, false);
    total_cost = 0; 
    vector<pi> edges;
}

void Graph::addEdge(int v, int w, int cost)
{
    adj[v].push_back(make_pair(w, cost));
}

bool sortbysec(const pi &a, const pi &b)
{
    return a.second < b.second;
}

int Graph::primMST(int src)
{
    Selected[src] = true;
    
    vector<pi>::iterator itr;
    for (itr = adj[src].begin(); itr != adj[src].end(); itr++)
    {
        if(Selected[(*itr).first] == false)
            edges.push_back((*itr));
    }
    while (!edges.empty())
    {
        sort(edges.begin(), edges.end(), sortbysec);
        auto x = edges.begin(); edges.erase(edges.begin());
        total_cost += (*x).second;
        primMST((*x).first);
    }
    

    // sort(edges.begin(), edges.end(), sortbysec);


    // int next = edges.front().first;
    // total_cost += edges.front().second;
    // primMST(next);
    return total_cost;
}

int main()
{
    fstream file;
    file.open("edges.txt");
    // file.open("sample2.txt");
    int v, e;
    file >> v >> e; // v = 500,  e = 2184
    Graph g(v);

    while (file.peek() != EOF)
    {
        int v , w, cost;
        file >> v >> w >> cost;
        g.addEdge(v, w, cost);
    }
    
    int answer = g.primMST(1);
    cout << answer << endl;

    return 0;
}
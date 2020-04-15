#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
class Graph
{
    int V; // # of vertices
    vector<pi>* adj; // vertex - vertex (cost)
    int total_cost ;
    vector<bool> Selected;
    vector<pi> temp;
public:
    Graph(int V);
    void addEdge(int v, int w, int cost);
    void primMST(int src);
    void showConndected(int vertex);
    int getTotalCost();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<pi>[V];
    vector<bool> Selected (V, false);
    total_cost = 0;
    
}

void Graph::addEdge(int v, int w, int cost)
{
    adj[v].push_back(make_pair(w, cost));
}

bool sortbysec(const pi &a, const pi &b)
{
    return a.second < b.second;
}

void Graph::primMST(int src)
{
    
    Selected[src] = true;
    cout << "SSI BAL" <<endl;
    for (vector<pi>::iterator itr = adj[src].begin(); itr != adj[src].end(); itr++)
    {
        if(Selected[(*itr).first] != true)
            temp.push_back(make_pair((*itr).first , (*itr).second));
    }
    sort(temp.begin(), temp.end(), sortbysec);
    
    if(!temp.empty())
    {
        int next = temp.front().first;
        total_cost += temp.front().second;
        vector<pi>::iterator itr = temp.begin();
        
        while (itr != temp.end())
        {
            if( (*itr).first == next)
            {
                temp.erase(itr);
                continue;
            }
            itr ++;
        }
        primMST(next);
    }
}

void Graph::showConndected(int vertex)
{   
    cout << "From the " << vertex << " there are : ";
    vector<pi>::iterator itr;
    for (itr = adj[vertex].begin(); itr != adj[vertex].end(); itr++)
    {
        cout << " " ;
        cout << (*itr).first << " cost : " << (*itr).second << endl;
    }   
}


int Graph::getTotalCost()
{
    return total_cost;
}

int main()
{
    fstream file;
    file.open("edges.txt");
    // file.open("sample2.txt");
    int V, e;
    file >> V >> e; // v = 500,  e = 2184
    Graph g(V);

    while (file.peek() != EOF)
    {
        int v , w, cost;
        file >> v >> w >> cost;
        g.addEdge(v, w, cost);
    }
    g.showConndected(4);

    g.primMST(1);
    //int result = g.getTotalCost();
    //cout << result << endl;

    return 0;
}
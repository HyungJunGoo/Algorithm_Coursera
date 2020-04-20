#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
class Graph
{
    int V; // # of vertices
    vector<pi>* adj; // vertex - vertex (cost)
    int total_cost ;

public:
    Graph(int V);
    void addEdge(int v, int w, int cost);
    void primMST(int src, vector<bool> Selected, vector<pi> temp);
    void showConndected(int vertex, vector<bool> Selected);
    int getTotalCost();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<pi>[V+1];
    total_cost = 0;
}

void Graph::addEdge(int v, int w, int cost)
{
    adj[v].push_back(make_pair(w, cost));
    adj[w].push_back(make_pair(v, cost));
}

bool sortbysec(const pi &a, const pi &b)
{
    return a.second < b.second;
}

void Graph::primMST(int src, vector<bool> Selected, vector<pi> temp)
{
    cout<<"start from "<< src << endl; 
    Selected[src] = true;
    if(src != V)
    {
        for (vector<pi>::iterator itr = adj[src].begin(); itr != adj[src].end(); itr++)
        {
            if(Selected[(*itr).first] != true)
                temp.push_back(make_pair((*itr).first , (*itr).second));
        }
    }
    sort(temp.begin(), temp.end(), sortbysec);
    // cout << "In temp: {";
    // for (vector<pi>::iterator itr = temp.begin(); itr != temp.end(); itr++)
    // {
    //     cout << (*itr).first <<  " &cost: " << (*itr).second << "  ";
    // }
    // cout << " }" << endl;
    if(!temp.empty())
    {
        sort(temp.begin(), temp.end(), sortbysec);
        int next = temp.front().first;
        cout << "\t" << "next is " << next << endl;
        total_cost += temp.front().second;
        cout << "\t" << "total cost so far: " <<  total_cost << endl;
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
        primMST(next, Selected, temp);
    }
}

void Graph::showConndected(int vertex, vector<bool> Selected)
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
    // file.open("sample3.txt");
    int V, e;
    file >> V >> e; // v = 500,  e = 2184
    Graph g(V);
    vector<bool> Selected (V+1, false);
    vector<pi> temp;

    while (file.peek() != EOF)
    {
        int v , w, cost;
        file >> v >> w >> cost;
        g.addEdge(v, w, cost);
    }
    g.primMST(2, Selected, temp);
    int result = g.getTotalCost();
    cout << result << endl;

    return 0;
}
// - 3612829
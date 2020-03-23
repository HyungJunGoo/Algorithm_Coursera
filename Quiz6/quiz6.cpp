#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;
using pi = pair<int, int>;
class Graph
{
    int V; // # of vertecies
    list<int>* adj;

    void dijkstra(Graph g, int src);
    

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void printSolution(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
}

priority_queue <pi,vector<pi>,greater<pi> > init_min_heap(int src, int size)
{
    priority_queue <pi,vector<pi>,greater<pi> >pq;
    pq.push(make_pair(0, src));
    for (int i = 1; i < size; i++)
    {
        pq.push(make_pair(INT16_MAX, i));
    }
    return pq;

}
int get_value(int v, int w)
{


}// get distance

void Graph::dijkstra(Graph g, int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT16_MAX;
    } // Initialise Distance Array
    dist[src - 1] = 0;

    priority_queue <pi,vector<pi>,greater<pi> >pq = init_min_heap(src - 1, V);
    
    pair<int, int> vertex = pq.top(); // (d, i)
    while (vertex.first != INT16_MAX)
    {
        pq.pop();
        int index = vertex.second;
        if (vertex.first <= dist[index])
        {
            list<int>::iterator i;
            for (i = adj[index].begin(); i != adj[index].end(); i++)
            {
                dist[*i] = dist[*i];
                if( dist[*i] > dist[index] + get_value(index, *i))
                    dist[*i] = dist[index] + get_value(index, *i);
                pq.push(make_pair(*i, dist[*i]));
            }
            
        }
        vertex = pq.top();
    }
    
}

int main()
{
    ifstream infile;
    infile.open("dijkstraData.txt");
    string buffer;
    vector<string> vecOfstring;

    while (infile.peek() != EOF)
    {
        getline(infile, buffer);
        vecOfstring.push_back(buffer);
    }
    // for (int i = 0; i < 200; i++)
    // {
    //     vecOfstring[i].erase(remove(vecOfstring[i].begin(), vecOfstring[i].end(), ','), vecOfstring[i].end());
    // }
     for (int i = 0; i < 200; i++)
    {
        replace(vecOfstring[i].begin(), vecOfstring[i].end(), ',', ' ');
    }
    
    
    int m = 0;
    vector<vector<int> > ret(200, vector<int> (m));
    for (int i = 0; i < 200; i++)
    {
        stringstream ss(vecOfstring[i]);
        int number;
        while (ss >> number)
        {
            ret[i].push_back(number);
        }
        
    }
    
    for (int i = 0; i < 200; i++)
    {
        cout << ret[i][4] << endl;
    }

    return 0;
}
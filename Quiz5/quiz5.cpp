#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <stack>
#include <vector>


using namespace std;

class Graph
{
    int V; // # of vertices
    list<int>* adj; // An array of adjacency lists
    void DFS_Loop(int s);
    void DFS(int v, bool visited[]);

    public:
    Graph(int V);

    void addEdge(int v, int w);
    
    Graph getRevGraph(Graph g);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

Graph Graph::getRevGraph(Graph g)
{
    list<int>::iterator i;
    Graph gr = Graph(V);
    for (int v = 0; v < V; v++)
    {
        for ( i = g.adj[v].begin(); i != g.adj[v].end(); i++)
        {
            gr.addEdge(*i, v);
        }
        
    }
    return gr;
    
}

int t = 0; // for finishing time
void Graph::DFS_Loop(int s)
{
    
    list<int> leader_list;
    bool* visited = new bool[V];
    for (int i = V; i > 0; i--)
    {
        if (!visited[i])
        {
            int leader = i;
            leader_list.push_back(leader);
            DFS(i, visited);
        }
    }
    
}

void Graph::DFS(int v, bool visited[])
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if(!visited[*i])
            DFS(*i, visited);
    }
    t++;
}

int main()
{
    ifstream file; file.open("SCC.txt");
    string buffer;
    vector<string> vecOfstring;
    
    while (file.peek() != EOF)
    {
        getline(file, buffer);
        vecOfstring.push_back(buffer);
    }
    int m = 0;
    vector<vector<int> > ret(5105043, vector<int> (m));
    for( int i = 0; i < 5105043; i++)
    {
        stringstream ss(vecOfstring[i]);
        int number;
        while (ss >> number)
        {
            ret[i].push_back(number);
        }
    }
    
    Graph g(875714);
    Graph gr(875714); 
    gr = gr.getRevGraph(g);
    for (int i = 0; i < 5105043; i++)
    {
        for(int j = 0; j < 1; j++)
            g.addEdge(ret[i][j], ret[i][j+1]);
        
    }
    cout << "Done" << endl;
    return 0;
}
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pi = pair<int, int>;
class Graph
{
    int V; // # of vertecies
    list<int>* adj;
    vector< vector <pair <int, int> > > nodes;
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void makeNodes(vector<vector<pair<int, int> > > vertices);
        void dijkstra(int src);
        void printSolution(int dist[] ,int v);
        int get_value(int v, int w);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.  0 would be null
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

vector< vector <pair <int, int> > > parse_data(vector<vector<int> > data, int size)
{
    vector< vector <pair <int, int> > > adj;
    
    for (int i = 0; i < size; i++)
    {
        int k = 1;
        int linesize = data[i].size();
        vector <pair <int, int> > temp; // (connected vertex, distance)
        while (k < (linesize - 1))
        {
            temp.push_back(make_pair(data[i][k], data[i][k+1])); // make ( connected vertex, distance)
            k += 2;
        }
        adj.push_back(temp);
        
    }
    
    return adj;
}

void Graph::makeNodes(vector<vector<pair<int,int> > > vertices)
{
    nodes = vertices;
}


int Graph::get_value(int v, int w)
{
    // vector<pair<int, int> >::iterator itr;
    int i = 0;
    int result;
    
    // for (itr = nodes[v].begin(); itr != nodes[v].end(); itr++, i++)
    // {
    //     if (itr[i].first == w)
    //     {
    //         result = itr[i].second;
    //         return result;
    //     }
    // }
    while (true)
    {
        if (nodes[v][i].first == w)
        {
            result = nodes[v][i].second;
            // cout << result <<endl;
            return result;
        }
        i++;
    }
    
        
    return result;

}// get distance
void Graph::printSolution(int dist[], int v)
{
    cout << "The shortest path to vertex #: " << v << " is " << dist[v-1] << endl;
}
void Graph::dijkstra(int src)
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
        cout << vertex.second << endl;
        // cout << dist[* adj[0].begin()] << endl;
        // cout << nodes[0][0].first << endl;
        
        

        if (vertex.first <= dist[index])
        {
            list<int>::iterator i;
            
            for (i = adj[index].begin(); i != adj[index].end(); i++)
            {
                dist[*i-1] = dist[*i-1];
                if( dist[*i-1] > dist[index] + get_value(index, *i))
                {
                    dist[*i-1] = dist[index] + get_value(index, *i);
                    pq.push(make_pair(dist[*i-1], *i-1));
                }
                
                // pq.push(make_pair(dist[*i-1], *i-1));
                // pair<int, int> test = pq.top();
                // cout << test.first << " , " << test.second << endl;
            }
        }
        // cout << "test spot" << endl;
        vertex = pq.top();
    } //7,37,59,82,99,115,133,165,188,197.
    printSolution(dist, 7);
    printSolution(dist, 37);
    printSolution(dist, 59);
    printSolution(dist, 82);
    printSolution(dist, 99);
    printSolution(dist, 115);
    printSolution(dist, 133);
    printSolution(dist, 165);
    printSolution(dist, 188);
    printSolution(dist, 197);
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
    
    vector< vector <pair <int, int> > > vertices(200);
    Graph g(200);
    vertices = parse_data(ret, 200);

    for (int i = 0; i < 200; i++)
    {
        int j = 0;
        while (j < (ret[i].size() - 1)/2)
        {
            g.addEdge(i, vertices[i][j].first); 
            j += 1;
        }
    }
    
    g.makeNodes(vertices);
    g.dijkstra(1);
    

    // for (int i = 0; i < 200; i++)
    // {
    //     cout << ret[i][4] << endl;
    // }

    return 0;
}
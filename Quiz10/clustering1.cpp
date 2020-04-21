/*
This file describes a distance function (equivalently, a complete graph with edge costs). It has the following format:

[number_of_nodes]

[edge 1 node 1] [edge 1 node 2] [edge 1 cost]

[edge 2 node 1] [edge 2 node 2] [edge 2 cost]

...

There is one edge (i,j) for each choice of 1≤i<j≤n, where n is the number of nodes.

For example, the third line of the file is "1 3 5250", indicating that the distance between nodes 1 and 3 (equivalently, the cost of the edge (1,3)) is 5250. You can assume that distances are positive, but you should NOT assume that they are distinct.

Your task in this problem is to run the clustering algorithm from lecture on this data set, where the target number k of clusters is set to 4. What is the maximum spacing of a 4-clustering?
*/

#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;


class Graph
{
private:
    int V;
    vector<pi>* edges; // vector[edge] = ( vertex1 , vertex2)
    vector<int> edge_list;
    
public:
    Graph(int V);
    void addEdge(int v, int w, int edge);
    void set_edge_list(int edge);
    int get_min_edge();
};


Graph::Graph(int V)
{
    this->V = V;
    edges = new vector<pi>[V+1];
}

void Graph::addEdge(int v, int w, int edge)
{
    edges[edge].push_back(make_pair(v, w));
    
    edge_list.push_back(edge);
}

int Graph::get_min_edge()
{
    vector<int>::iterator itr;
    sort(edge_list.begin(), edge_list.end());
    return edge_list.front();
}


int main()
{
    fstream file;
    file.open("clustering1.txt");
    int V; // # of vertices
    file >> V;
    
    Graph g(V);
    while (file.peek() != EOF)
    {
        int v, x, edge;
        file >> v >> x >> edge;
        g.addEdge(v, x, edge);
    }
    
    int answer = g.get_min_edge();
    // cout << answer << endl;
    int num_of_group = V;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// C++ implementation of kosaraju's algorithm to print SCC.


class Graph
{
    int V; // # of vertices
    list<int>* adj; // An array of adjacency lists. 
    // Fills stack with vertices in increasing order of finishing time.

    // The top element of stack has the maximum of finishing time.
    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // A recursive function to print DFS starting from v.
    void DFSUtil(int v, bool visited[]);

    public:
        Graph (int V);
        void addEdge(int v, int w);

        // The main function that find and print strongly connected components.
        void printSCCs();
        // Function that returns reverse (or transpose) of the graph.
        Graph getTranspose();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int> [V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int>& Stack){
    // Mark the current node as visited.
    visited[v] = true;

    // Recur all the vertices adjacent to this vertex.
    list<int>::iterator i;

    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(visited[*i] == false)
            fillOrder(*i, visited, Stack);
    }
    // all vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// A recursive function to print DFS starting from v 
void Graph::DFSUtil(int v, bool visited[]){
    // Mark the current node as visited and print it.
    visited[v] = true;
    cout << v << " ";
    
    // Recur all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(visited[*i] == false)
            DFSUtil(*i, visited);
    }

}

Graph Graph::getTranspose()
{
    Graph g(V);
    for(int v = 0; v<V; v++){
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++){
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

// The main function that find and prints all the Strongly connected components
void Graph::printSCCs(){
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Fill vertices in stack according to their finishing time
    for(int i = 0; i < V; i++){
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
    }

    // Create a reversed Graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited(for second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    // Now process all vertices in order defined by Stack
    while(Stack.empty() == false){
        //Pop verex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected components of the popped vertex
        if(visited[v] == false){
            gr.DFSUtil(v, visited );
            cout << endl;
        }
    }
} // end PrintSCCS()


int main()
{
    fstream file;
    int E;
    file >> E;
    Graph gr(2*E+1);
    while (file.peek() != EOF)
    {
        int start, end;
        file >> start >> end;
        gr.addEdge(start+(E+1), end+(E+1));
    }
    gr.printSCCs();

    return 0;
}

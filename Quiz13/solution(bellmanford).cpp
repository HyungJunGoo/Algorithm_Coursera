#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// A utility fuction used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex distance from Source\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t\t%d\n", i, dist[i]);
}
int printShortestPath(int dist[], int n)
{
    printf("SHORTEST PATH\n");
    int shortest = 10000000;
    for(int i = 0; i < n ; i++){
        if(dist[i] < shortest){
            shortest = dist[i];
        }
    }
    // printf("%d\n", shortest);
    return shortest;
}

int BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i = 0; i<=V; i++){
        for(int j = 0; j<E; j++){
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    
    for(int i = 0; i < E; i++){
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
            printf("Graph contains negative-cost cycle\n");
            return 0;
        }
    }
    //printArr(dist, V);
    return printShortestPath(dist, V);
}

int main()
{
    fstream file;
    file.open("g3.txt");

    int V, E;
    file >> V >> E;
    struct Graph* graph = createGraph(V, E);
    int i =0;
    while (file.peek() != EOF)
    {
        int t, h, c;
        file >> t >> h >> c;
        graph->edge[i].src = t;
        graph->edge[i].dest = h;
        graph->edge[i].weight = c;
        i++;
    }
    int result = 1000000;
    for (int i = 0; i < V; i++)
    {
        int candidate = BellmanFord(graph, i);
        if (result > candidate)
            result = candidate;
    }
    
    cout << result << endl;

    return 0 ;
}
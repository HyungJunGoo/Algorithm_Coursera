#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<string> bits;

public:
    Graph (int V);
    void put_bits(int i, int bit);
};

Graph::Graph(int V) : bits (V+1)
{
    this->V = V;
}

void Graph::put_bits(int i, int bit) // i = # of nodes
{
    string number = to_string(bit);
    bits[i] = number;
}

int main()
{
    ifstream file;
    file.open("clustering_big.txt");
    int nodes, bits;
    file >> nodes >> bits;
    int i = 1;
    while (file.peek() != EOF)
    {
    }
    

    return 0;
}
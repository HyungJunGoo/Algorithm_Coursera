#include <bits/stdc++.h>
using namespace std;
using PI=pair<int, int>;
class Graph
{
    int V;
    map<PI, int> edge;
    vector<int> selected;
    
    public:
        Graph (int V);
        void add_edge(int v, int w, int edge);
        void clustering();
        int get_head(int v);
};

Graph::Graph (int V) : selected(V+1, 0)
{
    this->V = V;
}

void Graph::add_edge(int v, int w, int _edge)
{
    PI temp = make_pair(v, w);
    edge[temp] = _edge;
}

bool sortbysec(const pair<PI, int> &a, const pair<PI, int> &b)
{
    return a.second < b.second;
}

int Graph::get_head(int v)
{
    if (selected[v] == v)
    {
        int result = selected[v];
        return result;
    }
    int temp = selected[v];
    int result = get_head(temp);
    return result;
}

void Graph::clustering()
{
    int k = V;
    for (int i = 1; i <= V ; i++)
    {
        selected[i] = i;
    }
    int result;
    while ( k >= 4)
    {
        pair<PI, int> min = *min_element(edge.begin(), edge.end(), sortbysec);
        // cout << "# of k is : " << k << endl;
        // cout << "min edge is : " << min.second << " =>  ( " << min.first.first << " , " << min.first.second << " )" << endl;  
        // cout << endl;
        
        if( get_head(min.first.first) != get_head(min.first.second))
        {
            selected[get_head(min.first.second)] = get_head(min.first.first);
            result = min.second;
            edge.erase(min.first);
            k--;
        }
        else
        {
            edge.erase(min.first);
            continue;
        }
    }
    // for(vector<int>::iterator itr = selected.begin(); itr != selected.end(); itr++)
    //     cout << *itr << " ";
    // cout << endl;
    cout << result << endl;
}


int main()
{
    fstream file;
    file.open("clustering1.txt");
    int V;
    file >> V;
    Graph g(V);
    while (file.peek() != EOF)
    {
        int v, w , edge;
        file >> v >> w >> edge;
        g.add_edge(v, w, edge);
    }
    
    g.clustering();


    return 0;
}
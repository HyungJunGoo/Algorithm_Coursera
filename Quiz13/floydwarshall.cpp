#include <bits/stdc++.h>

using namespace std;
#define INF 1000000
int main()
{
    fstream file;
    file.open("g3.txt");
    int v, e; // vertices, edges
    file >> v >> e;
    cout << v << endl;
    vector<vector<int> > gr(v+1, vector<int> (v+1, INF));
    // vector<vector<int> > gr2(4, vector<int>(4, 1000000));


    while (file.peek() != EOF)
    {
        int t, h, c; // tail head cost
        file >> t >> h >> c;
        gr[t][h] = c;
    }

    for (int i = 1; i <= v; i++)
    {
        gr[i][i] = 0;
    }
    
    // k 거쳐가는 노드
    for(int k = 1; k <= v; k++){
        // i 출발 노드
        for(int i = 1; i <= v; i++){
            // j 도착 노드
            for (int j = 1; j<=v; j++){
                if(gr[i][k] != INF && gr[k][j] != INF && (gr[i][k] + gr[k][j] < gr[i][j]))
                    gr[i][j] = gr[i][k] + gr[k][j];
            }
            if(gr[i][i] <0 ){
                cout << "Negative cycle found" << endl;
                return 0;
            }
        }
    }
    int shortest_path = INF;
    for(int i = 1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(j != i && gr[i][j] < shortest_path)
                shortest_path = gr[i][j];
        }
    }
    cout << shortest_path << endl;
    return 0;
}
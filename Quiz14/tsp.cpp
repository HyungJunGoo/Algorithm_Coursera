#include <bits/stdc++.h>

using namespace std;
#define V 25
#define MAX 9999999.0
typedef struct Node{
    double x;
    double y;
}node;

double getDistance(node &a, node &b){
    double dis=sqrt(pow((a.x - b.x),2.0) + pow((a.y - b.y),2.0));
    return dis;
}


double tsp(vector<vector<double> > dist, int visited, int s) 
{
    double ret = MAX;
    if(visited == (1<<V)-1) return 0;
    visited |= (1<<(s-1));
    for(int next = 1; next <= V; next++){
        if(dist[s][next] == 0 ) continue;
        if(visited & (1<<(next-1)) ) continue;
        ret = min(ret , tsp(dist, visited, next) + dist[s][next]);
    }
    cout << ret << endl;
    return ret;
} 

int main()
{
    fstream file;
    file.open("tsp.txt");
    int num;
    file >> num;
    vector<node> all_node;
    
    while (file.peek() != EOF)
    {
        double x_o;
        double y_o;
        file >> x_o >> y_o;
        node n; n.x = x_o; n.y = y_o;
        all_node.push_back(n);
    }
    vector<vector<double> > dist(num+1, vector<double>(num+1));
    
    for(int i=1;i<=num;i++){
        for(int j=1; j<=num; j++){
            if(i==j)
                dist[i][j] = 0;
            else{
                dist[i][j] = getDistance(all_node[i], all_node[j]);
            }
        }
    }
    // for(auto i : dist)
    //     {
    //         for(auto x : i)
    //             cout << x << " ";
    //         cout << endl;
    //     }
    
    int visited;
    visited = (1<<num); // 10'0000'0000'0000'0000'0000'0000
    
    cout << tsp(dist, visited, 1) << endl;
    return 0;
}

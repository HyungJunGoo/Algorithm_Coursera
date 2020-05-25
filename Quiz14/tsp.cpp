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
    double result;
    if( visited & (1<<(s-1)) ) return 0;
    else visited|=(1<<(s-1));
    for(int i=1; i<=V; i++){
        if(dist[s][i] == 0) continue;
        result = min()
    }
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
    
    int visited;
    visited = (1<<num); // 10'0000'0000'0000'0000'0000'0000
    
    return 0;
}

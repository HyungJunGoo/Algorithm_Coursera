#include <bits/stdc++.h>
using namespace std;
// using pi = pair<int, int>;

int main()
{
    fstream file; file.open("mwis.txt");
    int vertices;
    file >> vertices; // # of vertices
    vector<int> vertices_set (vertices+1);
    vector<int> check(vertices+1, 0);
    int i = 1;
    while (file.peek() != EOF)
    {
        int weight;
        file >> weight;
        vertices_set[i] = weight;
        i++;
    }
    i -=2; // to set i = 1000
    
    while (i >= 1)
    {
        if(vertices_set[i] < vertices_set[i-1])
        {
            check[i-1] = 1;
            i--; continue; 
        }
        else
        {
            check[i]= 1;
            i -=2; continue;
        }   
    }
    // for (int i = 1; i <= vertices; i++)
    //     cout << check[i] << " ";
    // cout << endl;
    //1, 2, 3, 4, 17, 117, 517, and 997
    int tocheck[8] = {1, 2, 3, 4, 17, 117, 517, 997};
    for (int j = 0; j < 8; j++)
    {
        cout << check[tocheck[j]] << " ";
    }
    cout << endl;
    
}
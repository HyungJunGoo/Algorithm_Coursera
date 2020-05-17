#include <bits/stdc++.h>
using namespace std;
int main()
{
    fstream file; file.open("knapsack_big.txt");    
    int knapsack_weight, nums;
    file >> knapsack_weight >> nums;
    vector<pair<int, int> > items (nums);
    int i = 0;
    while (file.peek() != EOF)
    {
        int _v, _w;
        file >> _v >> _w;
        items[i] = make_pair(_v, _w);
        i++;
    }


    return 0;
}
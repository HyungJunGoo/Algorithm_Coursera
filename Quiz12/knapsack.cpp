/* 
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]
...
For example, the third line of the file is "50074 659", indicating that the second item has value 50074 and size 659, 
respectively.You can assume that all numbers are positive. You should assume that item weights 
and the knapsack capacity are integers.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    fstream file; file.open("knapsack_big.txt");
    int _weight , nums;
    file >> _weight >> nums;
    vector<pair<int, int> > items (nums);
    int i = 0;
    while (file.peek() != EOF)
    {
        int _v, _n;
        file >> _v >> _n;
        items[i] = make_pair(_v, _n);
        i++;
    }
    int ** mat = new int*[nums+1];
    for (int i = 0; i < nums+1; i++)
    {
        mat[i] = new int[_weight+1];
    }
    for (int r = 0; r < _weight + 1; r++) {
        mat[0][r] = 0;
    }
    for (int c = 0; c < nums + 1; c++) {
        mat[c][0] = 0;
    }

    for (int item = 1; item <= nums; item++)
    {
        for (int capacity = 1; capacity <= _weight; capacity++)
        {
            int max_val_without_curr = mat[item-1][capacity];
            int max_val_with_curr = 0; //Initialise w/ 0
            int curr_weight = items[item-1].second;
            if(capacity >= curr_weight) {
                max_val_with_curr = items[item-1].first;
                int remain_capacity = capacity - curr_weight;
                max_val_with_curr += mat[item-1][remain_capacity];
            }
            mat[item][capacity] = max(max_val_without_curr, max_val_with_curr);
        }
        
    }
    cout << mat[nums][_weight] << endl;
    return 0;
}
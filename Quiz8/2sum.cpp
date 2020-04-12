#include <unordered_set>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
#define SIZE 1000000
#define MIN -10000
#define MAX 10000
int main()
{
    fstream file;
    file.open("2sum.txt");
    
    vector<long long> data_2 (SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        file >> data_2[i];
    }
    
    unordered_set<long long> table;
    for (int i = 0; i < SIZE; i++)
        table.insert(data_2[i]);
    
    int count = 0;
    
    for (long long i = MIN; i <= MAX; i++)
    {
        cout << "for " << i << " ~~ " << endl;
        unordered_set<long long> :: iterator itr = table.begin();
        
        for(itr = table.begin(); itr != table.end(); itr++)
        {
            long long y = i - (*itr);
            if(table.find(y) != table.end() && (*itr) != y)
            {
                count++;
                cout << "found #" << count << endl;
                break;
            }
        }
    }
    
    cout << count << endl;

    return 0;
}
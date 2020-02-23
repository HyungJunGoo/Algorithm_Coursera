
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define SIZE 100000
int main()
{
    ifstream ifs;
    int i;
    long long count;
    ifs.open("IntegerArray.txt");
    if (!ifs)
    {
        cerr << "Unable to open file!\n";
        exit(1);
    }
    string arr[SIZE];
    int arr2[SIZE];

    while (!ifs.eof())
    {
        getline(ifs, arr[i]);
        i++;
    }
    
    for (int j = 0; j < SIZE; j++)
    {
        arr2[j] = stoi(arr[j]);
    }
    
    for (int j = 0; j < SIZE - 1; j++)
    {
        for (int k = j+1; k < SIZE; k++)
        {
            if (arr2[k] < arr2[j])
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
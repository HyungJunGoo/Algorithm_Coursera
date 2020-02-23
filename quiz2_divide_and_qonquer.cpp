#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define SIZE 100000

long long count(int arr[], int len)
{
    if (len == 1) return 0;
    else
    {
        
        int x = count()
    }
    
    return 0;
}

long long countSplit(int arr[], int len)
{
    return 0;
}

void convStrToInt(string arr[], int arr2[])
{
    for (int j = 0; j < SIZE; j++)
    {
        arr2[j] = stoi(arr[j]);
    }
}

int main()
{
    ifstream ifs;
    int length = SIZE;
    long long answer;
    ifs.open("IntegerArray.txt");

    string arr[SIZE];
    int arr2[SIZE];
    convStrToInt(arr, arr2);

    answer = count(arr2, length);

    return 0;
}
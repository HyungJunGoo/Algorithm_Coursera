#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int* hashTable; // Pointer to an array containing buckets
    int curr_size;
    int TABLE_SIZE;
public:
    // function to check if hash table is full
    bool isFull()
    {
        return (curr_size == TABLE_SIZE);
    }

    int hash(int key)
    {
        return (key % TABLE_SIZE);
    }

    Hash()
    {
        hashTable = new int[TABLE_SIZE];
        curr_size = 0;
        TABLE_SIZE = 
    }

};
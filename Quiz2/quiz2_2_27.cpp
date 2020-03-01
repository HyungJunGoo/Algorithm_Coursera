#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100000

long long countInv(int arr[], int start, int mid, int end);

long long count(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start)/2;
        long long left_Inv = count(arr, start, mid);
        long long right_Inv = count(arr, mid+1, end);
        long long split_Inv = countInv(arr, start, mid, end);

        return left_Inv + right_Inv + split_Inv;
    }
    return 0;
}   

long long countInv(int arr[], int start, int mid, int end)
{
    int num_of_left = mid - start + 1;
    int num_of_right = end - mid;
    int left_arr[num_of_left];
    int right_arr[num_of_right];
    
    //copy half of the elements in the origin to each temporary arrays.
    for (int i=0; i<num_of_left; i++)
        left_arr[i] = arr[start + i];
    for (int i=0; i<num_of_right; i++)
        right_arr[i] = arr[mid+1+i];
    // end copy

    // Merge temporary array to origin in order and count inversion
    int i = 0; int j = 0; // i is left , j is right index
    int k = start; // iterator in arr[]
    long long count = 0;

    while ((i < num_of_left) && (j <num_of_right))
    {
        if (left_arr[i] < right_arr[j])
        {    
            arr[k] = left_arr[i];
            ++i;
        }
        else
        {
            arr[k] = right_arr[j];
            //cout << "(" << left_arr[i] << ',' << arr[k] << ")" << endl;
            ++j;
            count = count + num_of_left - i;
        }
        ++k;
    }

    //copy the rest of elements in both left, right temporary arrays to original array
    while (i < num_of_left)
    {
        arr[k] = left_arr[i];
        k++;
        i++;
    }
    while (j < num_of_right)
    {
        arr[k] = right_arr[j];
        k++;
        j++;
    }
    // end merge
    return count;
}

// function to convert string array to integer array
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
    long long inversionCount = 0;
    ifs.open("IntegerArray.txt");

    string arr[length];
    int num = 0;
    while (!ifs.eof())
    {
        getline(ifs, arr[num]);
        num++;
    }
    
    int arr2[length];
    convStrToInt(arr, arr2);
    cout << "check" << endl;
    inversionCount = count(arr2, 0, length-1);

    cout << "The number of inversion is : " << inversionCount << endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int first = arr[start]; int middle = arr[mid]; int last = arr[end];
    int temparr[] = {first, middle, last};
    int min = temparr[0]; int max = temparr[2];
    for (int i = 0; i < 3; i++)
    {
        if (temparr[i] < min)
            min = temparr[i];
        if (temparr[i] > max)
            max = temparr[i];
    } // find minimum and maximum among first, middle, last elements in array
    
    int pIndx = 0;
    for (int i = 0; i < 3; i++)
    {
        if ( temparr[i] != min && temparr[i] != max)
            pIndx = i;
    } // find pivot index in temparr
    for (int i = 0; i <= end; i++)
    {
        if (arr[i] == temparr[pIndx])
        {
            // arr[mid] = temparr[pIndx];
            // arr[start] = min; arr[end] = max;
            return i;
        }
    } // find pivot index in original array
    
    return mid;
}

int partition(int arr[], int start, int end)
{

    int pivotindex = median(arr, start, end);
    int pivot = arr[pivotindex];
    swap(arr[pivotindex], arr[start]);
    int i = start + 1;
    for (int j = i; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[j], arr[i]);
            i = i+1;
        }
    }
    swap(arr[i-1], arr[start]);
    return i-1;
    
}
int quickSort(int arr[], int start, int end, int count)
{
    // base case
   
    // Partition array arount pivot
    
    // i indicate the first element which is just between the element bigger and smaller than pivot 
    // j indicate right after the last element which is partitioned
    int n = end - start;
    if (start < end)
    {
        int piv = partition(arr, start, end);
        // End of Partition
        int left = quickSort(arr, start, piv - 1, count);
        int right = quickSort(arr, piv + 1, end, count);
        return count + left + right + n;
    }
    return 0;
} // End Quick Sort

// function to convert string array to integer array
void convStrToInt(string arr[], int arr2[], int size)
{
    for (int j = 0; j < size; j++)
    {
        arr2[j] = stoi(arr[j]);
    }
}

int main()
{
    ifstream file;
    file.open("QuickSort.txt");

    int size = 10000, comparison_count = 0;
    string arr[size];
    int num = 0;
    while (!file.eof())
    {
        getline(file, arr[num]);
        num++;
    }
    int IntArr[size];
    convStrToInt(arr, IntArr, size);

    int answer = quickSort(IntArr, 0, 9999, comparison_count);
    cout << answer << endl;    

    return 0;
}
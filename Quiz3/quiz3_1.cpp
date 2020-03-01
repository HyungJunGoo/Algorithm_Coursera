#include <iostream>
#include <fstream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int start, int end)
{

    int pivot = arr[start];
    int i = start + 1;
    for (int j = start + 1; j <= end; j++)
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
    if (start < end)
    {
        int piv = partition(arr, start, end);
        // End of Partition
        quickSort(arr, start, piv - 1, count);
        quickSort(arr, piv + 1, end, count);
    }
    count += end - start;
    return count;
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
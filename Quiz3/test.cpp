#include <iostream>
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
    
    return start;
}

int main()
{
    int arr[] = { 3, 7, 1, 4, 5, 61, 10};
    int answer = median(arr, 0, 6);
    cout << answer << "\n------" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<"  " << endl;
    }
    
}
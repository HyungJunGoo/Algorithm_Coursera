#include <iostream>
#include <fstream>
using namespace std;


long long split_count(int arr[], int low, int mid, int len);

// void swap(int* a, int* b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

long long count(int arr[], int start, int end)
{
    if (start == end) return 0;
    int mid = start + (end - start)/2;
    long long lft_splt = count(arr, start, mid);
    long long rgt_splt = count(arr, mid+1, end);
    long long splt_cnt = split_count(arr, start, mid, end);
    // cout << "-----" << endl;
    return lft_splt + rgt_splt + splt_cnt;
}

long long split_count(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    
    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    for (int i=0; i < n1; i++)
        leftArr[i] = arr[start + i];
    for (int i=0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0;
    int k = start;
    long long count = 0;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }

        else
        {
            arr[k] = rightArr[j];
            j++;
            count += n1 - i;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = rightArr[j];
        k++; j++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        k++; j++;
        count += n1 - i;
    }
    delete [] leftArr;
    delete [] rightArr;

    return count;
    
}

int main()
{
    int testarr[4] = {1, 2, 3, 4};
    long long answer = count(testarr, 0, 4);
    cout << answer << endl;
    return 0;
}
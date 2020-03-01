#include <iostream>
#include <fstream>
#define SIZE 100000
using namespace std;

long int split_count(int arr[], int low, int mid, int len);

long int count(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start)/2;
        long int lft_splt = count(arr, start, mid);
        long int rgt_splt = count(arr, mid+1, end);
        long int splt_cnt = split_count(arr, start, mid, end);
        return lft_splt + rgt_splt + splt_cnt;
    }
    return 0;
}

long int split_count(int arr[], int start, int mid, int end)
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
    long int count = 0;

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
        arr[k] = rightArr[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        k++;
        j++;
        //count += n1 - i;
    }
    delete [] leftArr;
    delete [] rightArr;

    return count;
}

void convStrToInt(string arr[], int arr2[])
{
  for (int j = 0; j < SIZE; j++)
  {
    arr2[j] = stoi(arr[j]);
  }
}

int main(void)
{
    ifstream ifs;
    int length = SIZE;
    long long answer;
    ifs.open("IntegerArray.txt");

    string arr[SIZE];
    int num = 0;
    while (!ifs.eof())
    {
        getline(ifs, arr[num]);
        num++;
    }
    int arr2[SIZE];
    convStrToInt(arr, arr2);

    answer = count(arr2, 0, length);
    cout << answer << endl;




    int testarr[4] = {1, 2, 3, 4};
    long long answer2 = count(testarr, 0, 4);
    cout << answer2 << endl;
    return 0;
}
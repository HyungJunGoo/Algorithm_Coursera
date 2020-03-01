#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5};
    int i = 0;
    int j = 2;
    swap(arr[i], arr[j]);
    for (int z = 0; z < 5; z++)
    {
        cout << arr[z] << endl;
    }
    cout << "i is : " << i << endl;
    cout << "j is : " << j << endl;
}
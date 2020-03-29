#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

void putHeapLow(priority_queue<int> max_heap, int val)
{
    max_heap.push(val);
}

void putHeapHigh(priority_queue<int,vector<int>, greater<int> > min_heap, int val)
{
    min_heap.push(val);
}

int getMedian(priority_queue<int> max_heap)
{
    return max_heap.top();
}
int main()
{
    ifstream infile;
    infile.open("Median.txt");   
    string buffer;
    vector<string> vecOfstring;

    while(infile.peek() != EOF)
    {
        getline(infile,buffer);
        vecOfstring.push_back(buffer);
    }
    vector<int> data;
    for(int i = 0; i < 10000; i++)
    {
        stringstream ss (vecOfstring[i]);
        int number;
        ss >> number;
        data.push_back(number);
    }
    
    vector<int> med_of_all;
    priority_queue<int, vector<int>, greater<int> > min_heap; // HEAP HIGH
    priority_queue<int> max_heap; // HEAP LOW
    int num_of_HL = 1; int num_of_HH = 0; 
    max_heap.push(data[0]);
    med_of_all.push_back(data[0]);
    for(int i = 1; i < 10000; i++)
    {
        if (num_of_HL > num_of_HH)
        {
            
            if (max_heap.top() > data[i])
            {
                int tomove = max_heap.top();
                max_heap.pop();
                max_heap.push(data[i]);
                min_heap.push(tomove);
                num_of_HH++;
                med_of_all.push_back(max_heap.top());
                continue;
            }
            
            int tomove = max_heap.top();
            max_heap.pop();
            min_heap.push(tomove);
            num_of_HH++;
            max_heap.push(data[i]);
            med_of_all.push_back(max_heap.top());
            continue;
        }
        else if (num_of_HL == num_of_HH)
        {
            
            if (min_heap.top() < data[i])
            {
                int tomove = min_heap.top();
                min_heap.push(data[i]);
                min_heap.pop();
                max_heap.push(tomove);
                num_of_HL++;
                med_of_all.push_back(max_heap.top());
                continue;
            }
            max_heap.push(data[i]);  
            num_of_HL++; 
            med_of_all.push_back(max_heap.top());
            continue;
        } 
    }
    cout << med_of_all[0] << endl;
    int ans = 0; 
    for (int i = 0; i < 10000; i++)
    {
        ans += med_of_all[i];
    }
    cout << ans << endl;
    return 0;
}
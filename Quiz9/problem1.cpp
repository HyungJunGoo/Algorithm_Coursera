#include <bits/stdc++.h>

using namespace std;

bool diffcomapre(pair<int, pair<int, int> >  &a, pair<int, pair<int, int> > &b)
{
    int A = a.second.first - a.second.second;
    int B = b.second.first - b.second.second;
    
    if (A == B)
    {
        return a.second.first > b.second.first;
    }
    return A > B;
}

int main()
{
    int SIZE;
    queue<int> list;
    vector<pair<int, pair<int, int> > > tasks;
    
    fstream file;
    file.open("jobs.txt");
    // file.open("sample.txt");
    file >> SIZE; 
    for (int i = 0; i < SIZE; i++)
    {
        int a , b;
        file >> a >> b;
        tasks.push_back(make_pair(i+1, make_pair(a, b)));
    }
    sort(tasks.begin(), tasks.end(), diffcomapre);

    long long sumtime = 0; 
    long long sumlength = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        sumlength += tasks[i].second.second;
        sumtime += sumlength * tasks[i].second.first;
    }
    cout << sumtime << endl;
    return 0;
}

// Answer : 69119377652
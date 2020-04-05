#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream file;
    file.open("2sum.txt");
    string buffer;
    vector<string> vecofstr;
    
    while (file.peek() != EOF)
    {
        getline(file, buffer);
        vecofstr.push_back(buffer);
    }
    vector<int> data2;
    cout << vecofstr[0] << endl;
    for (int i = 0; i < vecofstr.size(); i++)
    {
        stringstream ss (vecofstr[i]);
        int number;
        ss >> number;
        data2.push_back(number);
    }
    cout << data2[0] << endl;
    
    return 0;
}
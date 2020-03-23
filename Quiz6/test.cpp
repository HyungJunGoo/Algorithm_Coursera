#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("dijkstraData.txt");
    string buffer;
    vector<string> vecOfstring;

    while (infile.peek() != EOF)
    {
        getline(infile, buffer);
        vecOfstring.push_back(buffer);
    }
    // for (int i = 0; i < 200; i++)
    // {
    //     vecOfstring[i].erase(remove(vecOfstring[i].begin(), vecOfstring[i].end(), ','), vecOfstring[i].end());
    // }
     for (int i = 0; i < 200; i++)
    {
        replace(vecOfstring[i].begin(), vecOfstring[i].end(), ',', ' ');
    }
    
    
    int m = 0;
    vector<vector<int> > ret(200, vector<int> (m));
    for (int i = 0; i < 200; i++)
    {
        stringstream ss(vecOfstring[i]);
        int number;
        while (ss >> number)
        {
            ret[i].push_back(number);
        }
        
    }
    
    for (int i = 0; i < 200; i++)
    {
        cout << ret[i][4] << endl;
    }
    
    return 0;
}
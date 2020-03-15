#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;



int main()
{
    ifstream infile; infile.open("kargerMinCut.txt");
    string buffer;
    vector<string> vecOfstring;
    
    while (infile.peek() != EOF)
    {
        getline(infile, buffer);
        vecOfstring.push_back(buffer);
        
    }
    // cout << vecOfstring[0] << endl;

    
    int m = 0;
    vector<vector<int> > ret( 200 , vector<int> (m));
    for(int i = 0; i< 200; i++)  
    {
        stringstream ss(vecOfstring[i]);
        int number;
        while (ss >> number)
        {
            ret[i].push_back(number);
        }
        
    }
    cout << ret[199][0] << endl;
    // for (int i = 0; i < 200; i++)
    // {
    //     cout << endl << ret[i]  << endl;
    // }
}
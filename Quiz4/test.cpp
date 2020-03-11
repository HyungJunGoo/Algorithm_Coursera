#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


vector<string> getFileContent(string fileName, vector<string> vecOfstrs)
{
    ifstream infile;
    infile.open(fileName);
    if(!infile)
    {
        cerr << "Cannot open the file: " << fileName << endl;
        return vecOfstrs;        
    }
    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(infile, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0 )
            vecOfstrs.push_back(str);
    }
    infile.close();
    return vecOfstrs;
}

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
    vector<int> ret;
    for(vector<string>::iterator it= vecOfstring.begin();it!=vecOfstring.end();++it)
    {
        istringstream iss(*it);
        int temp;
        iss >> temp;
        ret.push_back(temp);
    }  

    for (int i = 0; i < 200; i++)
    {
        cout << endl << ret[i]  << endl;
    }
}
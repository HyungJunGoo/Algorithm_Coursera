#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str ;
    getline(cin, str);

    cout << "first string: " << str << "\n" << endl;
    str.push_back('s');
    cout << "after push back" << str << "\n" << endl;
    str.pop_back();
    cout << "after pop back" << str << "\n" << endl;
    
    int a = 10;
    string s = to_string(a);
    cout << s << endl;
    return 0;
}
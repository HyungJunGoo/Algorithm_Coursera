#include <bits/stdc++.h>
using namespace std;



int main()
{
    vector<bool> a (4, false);
    a[15] = true;
    cout << a.size() << endl;
    if(a[0] == true)
        cout << "check " << endl;
    
    return 0;
}
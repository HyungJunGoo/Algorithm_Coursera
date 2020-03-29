#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > que ; 
    priority_queue<int> max_qu;
    max_qu.push(10);
    cout << max_qu.top() << endl;
    max_qu.push(12);
    cout << max_qu.top() << endl;
    max_qu.pop();
    cout << max_qu.top() << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
    return lhs.second < rhs.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    pq.push(make_pair(1, 2));
    pq.push(make_pair(2, 6));
    pq.push(make_pair(3, 4));
    pq.push(make_pair(6, 1));

    cout << pq.top().first << endl;
    return 0;
}
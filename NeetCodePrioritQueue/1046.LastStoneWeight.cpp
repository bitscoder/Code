#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i : stones)
    {
        pq.push(i);
    }
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (x != y)
        {
            pq.push(abs(x - y));
        }
    }
    return pq.empty() ? 0 : pq.top();
}
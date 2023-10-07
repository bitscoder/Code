#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
priority_queue<int, vector<int>, greater<int>> pq;
int k = 0;
KthLargest(int k, vector<int> &nums)
{
    this->k = k;
    for (int i : nums)
    {
        pq.push(i);
    }
    while (pq.size() != this->k)
    {
        pq.pop();
    }
}

int add(int val)
{
    if (val > pq.top())
    {
        pq.pop();
        pq.push(val);
    }
    return pq.top();
}
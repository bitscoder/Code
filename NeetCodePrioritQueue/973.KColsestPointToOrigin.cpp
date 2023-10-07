#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        double value = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][0]);

        pq.push({value, points[i]});
    }
    vector<vector<int>> ansVector;
    while (k != 0)
    {
        ansVector.push_back(pq.top().second);
        pq.pop();
        k--;
    }
}
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    return pq.top();
}
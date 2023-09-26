#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<pair<int, int>> adjList[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            adjList[i].push_back(make_pair(j, distance));
            adjList[j].push_back(make_pair(i, distance));
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> tapVector(n, 0);
    pq.push({0, 0});
    int ansSum = 0;
    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();
        tapVector[front.second] = 1;
        ansSum += front.first;
        for (auto i : adjList[front.second])
        {
            if (tapVector[i.first] == 1)
                pq.push({i.second, i.first});
        }
    }
    return ansSum;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<int> neighbors[n];
        unordered_set<int> adjList[n];
        for (int i = 0; i < connections.size(); i++)
        {
            neighbors[connections[i][0]].emplace_back(connections[i][1]);
            neighbors[connections[i][1]].emplace_back(connections[i][0]);
            adjList[connections[i][0]].insert(connections[i][1]);
        }
        int ans = 0;
        queue<int> helperQueue;
        helperQueue.push(0);
        vector<int> visited(n, 0);
        while (!helperQueue.empty())
        {
            int cur = helperQueue.front();
            visited[cur] = 1;
            helperQueue.pop();
            int neighborsCount = neighbors[cur].size();
            for (int i = 0; i < neighborsCount; i++)
            {
                if (adjList[neighbors[cur][i]].find(cur) == adjList[neighbors[cur][i]].end())
                {
                    ans++;
                }
                if (visited[neighbors[cur][i]] == 0)
                {
                    helperQueue.push(neighbors[cur][i]);
                }
            }
        }
        return ans;
    }
};

int getLastMoment(int n, vector<int> &left, vector<int> &right)
{
    sort(left.begin(), left.end(), greater<int>());
    sort(right.begin(), right.end());
    return max(left[0], n - right[0]);
}

class Solution
{
private:
    vector<string> possible1(string str)
    {
        vector<string> ans;
        for (int i = 0; i < 4; i++)
        {
            int dig = stoi(str.substr(i, 1));
            stringstream ss;
            ss << (dig + 1) % 10;
            if (i == 0)
            {
                ans.push_back(ss.str() + str.substr(i + 1));
            }
            else if (i == 3)
            {
                ans.push_back(str.substr(0, i) + ss.str());
            }
            else
            {
                ans.push_back(str.substr(0, i) + ss.str() + str.substr(i + 1));
            }
            stringstream ss1;
            ss1 << ((dig - 1 + 10) % 10);
            if (i == 0)
            {
                ans.push_back(ss1.str() + str.substr(i + 1));
            }
            else if (i == 3)
            {
                ans.push_back(str.substr(0, i) + ss1.str());
            }
            else
            {
                ans.push_back(str.substr(0, i) + ss1.str() + str.substr(i + 1));
            }
        }
        return ans;
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_map<string, int> um;
        int n = deadends.size();
        for (int i = 0; i < n; i++)
        {
            um[deadends[i]] = 1;
        }
        queue<pair<string, int>> helperQueue;
        helperQueue.push({"0000", 0});

        while (!helperQueue.empty())
        {
            pair<string, int> cur = helperQueue.front();
            helperQueue.pop();
            um[cur.first] = 1;
            if (cur.first == target)
            {
                return cur.second;
            }
            vector<string> possible = possible1(cur.first);
            for (int i = 0; i < 8; i++)
            {
                if (um[possible[i]] == 0)
                    continue;
                helperQueue.push({possible[i], cur.second + 1});
            }
        }
        return -1;
    }
};

int findChampion(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> adjList[n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                adjList[j].push_back(i);
            }
            else
            {
                adjList[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (adjList[i].size() == 0)
        {
            return i;
        }
    }
    return -1;
}
int findChampion(int n, vector<vector<int>> &edges)
{
    vector<int> adjList[n];
    int m = edges.size();
    for (int i = 0; i < m; i++)
    {
        adjList[edges[i][0]].push_back(adjList[i][1]);
    }
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (adjList[i].size() == 0)
        {
            count++;
            ans = i;
        }
    }
    if (count == 1)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int getWinner(vector<int> &arr, int k)
{
    int cur = arr[0];
    int i = 1;
    int count = 0;
    while (i != arr.size())
    {
        if (cur > arr[i])
        {
            count++;
            arr.push_back(arr[i]);
        }
        else
        {
            arr.push_back(cur);
            cur = arr[i];
            count == 0;
        }
        if (count == k)
        {
            return cur;
        }
    }
    return -1;
}
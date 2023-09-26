#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pair<int, int>> adjList[n];
    for (auto i : times)
    {
        adjList[i[0] - 1].push_back({i[1] - 1, i[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n, false);
    pq.push({0, k - 1});
    int ans = 0;
    while (!pq.empty())
    {
        auto a = pq.top();
        pq.pop();
        if (visited[a.second])
            continue;

        visited[a.second] = true;
        ans += a.first;

        for (auto i : adjList[a.second])
            if (!visited[i.first])
                pq.push({i.second, i.first});
    }
    for (auto i : visited)
        if (!i)
            return -1;
    return ans;
}
int countOnesInBinary(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1); // Flip the rightmost 1 bit to 0
        count++;
    }
    return count;
}
int sumIndicesWithKSetBits(vector<int> &nums, int k)
{

    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int count = countOnesInBinary(nums[i]);

        if (count == k)
        {
            ans += i;
        }
    }
    return ans;
}
/*
Input: nums = [6,0,3,3,6,7,2,7]
Output: 3
Explanation:
The three possible ways are:
The class teacher selects the student with index = 1 to form the group.
The class teacher selects the students with index = 1, 2, 3, 6 to form the group.
The class teacher selects all the students to form the group.

The student is selected and the total number of selected students is strictly greater than nums[i].
The student is not selected and the total number of selected students is strictly less than nums[i].
*/
/*
Input: nums = [1,1]
Output: 2
Explanation:
The two possible ways are:
The class teacher selects no student.
The class teacher selects both students to form the group.
If the class teacher selects just one student to form a group then the both students will not be happy. Therefore, there are only two possible ways.

*/
int countWays(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 >= nums[i])
            count++;
    }
    return count;
}

int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
{
    int maxAlloys = 0;
    for (int i = 0; i < k; i++)
    {
        int currMin = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (composition[i][j] == 0)
                continue;
            currMin = min(currMin, stock[j] / composition[i][j]);
        }
        maxAlloys = max(maxAlloys, currMin);
    }

    int minCost = INT_MAX;
    int index = 0;

    for (int i = 0; i < k; i++)
    {
        int currCost = 0;
        for (int j = 0; j < n; j++)
        {
            currCost += cost[j] * composition[i][j];
        }
        if (minCost > currCost)
        {
            index = i;
            minCost = currCost;
        }
    }
    return budget / minCost + maxAlloys;
}
int countWays(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    sort(nums.begin(), nums.end());
    if (nums[0] != 0)
        cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i + 1 > nums[i])
        {
            if (i + 1 < n && i + 1 < nums[i + 1])
                cnt++;
            else if (i + 1 == n)
                cnt++;
        }
    }
    return cnt;
}
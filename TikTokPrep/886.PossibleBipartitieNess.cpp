#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << !1 << endl;
}
/*
Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
*/
bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<int> adjList[n + 1];
    vector<int> first(n + 1, 0);
    vector<int> second(n + 1, 0);
    int e = dislikes.size();
    for (int i = 0; i < e; i++)
    {
        adjList[dislikes[i][0]].push_back(dislikes[i][1]);
    }
    vector<int> visited(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        if (visited[i])
            continue;
        queue<pair<int, int>> helperQueue;
        helperQueue.push({i, 0});
        while (!helperQueue.empty())
        {
            pair<int, int> currentNode = helperQueue.front();
            helperQueue.pop();
            visited[currentNode.first] = 1;
            // if (visited[currentNode.first])
            //     continue;
            if (currentNode.second)
                first[currentNode.first]++;
            else
                second[currentNode.first]++;
            // visited[currentNode.first] = 1;
            for (int i = 0; i < adjList[currentNode.first].size(); i++)
            {
                // if (!visited[adjList[currentNode.first][i]])
                //{
                helperQueue.push({adjList[currentNode.first][i], !currentNode.second});
                //}
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (first[i] > 0 && second[i] > 0)
            return false;
    }
    return true;
}

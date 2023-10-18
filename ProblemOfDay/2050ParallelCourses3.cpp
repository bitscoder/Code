#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{

    vector<int> adjList[n];
    int relationsSize = relations.size();
    vector<int> indegreeHelper(n, 0);
    for (int i = 0; i < relationsSize; i++)
    {
        adjList[relations[i][0] - 1].push_back(relations[i][1] - 1);
        indegreeHelper[relations[i][1] - 1]++;
    }
    queue<tuple<int, int, int>> helperQueue;

    for (int i = 0; i < n; i++)
    {
        if (indegreeHelper[i] == 0)
        {
            helperQueue.push({i, 0, time[i]});
        }
    }
    int ansCount = 0;
    while (!helperQueue.empty())
    {
        int curCount = 0;
        int curIndex = get<1>(helperQueue.front());
        while (get<1>(helperQueue.front()) == curIndex)
        {
            tuple<int, int, int> curEle = helperQueue.front();
            helperQueue.pop();
            curCount = max(curCount, get<2>(curEle));
            for (int i = 0; i < adjList[get<0>(curEle)].size(); i++)
            {
                indegreeHelper[adjList[get<0>(curEle)][i]]--;
                if (indegreeHelper[adjList[get<0>(curEle)][i]] == 0)
                {
                    helperQueue.push({adjList[get<0>(curEle)][i], get<1>(curEle) + 1, time[adjList[get<0>(curEle)][i]]});
                }
            }
        }
        ansCount += curCount;
    }
    return ansCount;
}
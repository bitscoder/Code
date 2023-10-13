#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int back(int l, unordered_map<int, vector<int>> &um)
{
    if (um.find(l) == um.end())
    {
        return 1;
    }
    int count = 0;
    int n = um[l].size();
    for (int i = 0; i < n; i++)
    {
        count += back(um[l][i], um);
    }
    return 2 * count;
}
int scoreOfParentheses(string s)
{
    stack<int> helperStack;
    vector<pair<int, int>> helperVector;
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '(')
        {
            helperStack.push(i);
        }
        else
        {
            int cur = helperStack.top();
            helperStack.pop();
            if (!helperStack.empty())
                helperVector.push_back({helperStack.top(), cur});
            else
                helperVector.push_back({-1, cur});
        }
    }
    //(()())
    unordered_map<int, vector<int>> um;
    int m = helperVector.size();
    for (int i = 0; i < m; i++)
    {
        if (um.find(helperVector[i].first) != um.end())
        {
            um[helperVector[i].first].push_back(helperVector[i].second);
        }
        else
        {
            um[helperVector[i].first] = vector<int>();
            um[helperVector[i].first].push_back(helperVector[i].second);
        }
    }
    return back(-1, um) / 2;
}

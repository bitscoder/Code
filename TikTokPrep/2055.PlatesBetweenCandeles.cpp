#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
{
    vector<int> dp(s.size(), 0);
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            count++;
        }
        else
        {
            dp[i] = count;
        }
    }
    vector<int> ansVector;
    for (int i = 0; i < queries.size(); i++)
    {
        int ansCount;
        bool flag = false;
        int countbefore = 0;
        for (int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            if (flag == false && dp[j] != 0)
            {
                countbefore = dp[j];
                flag = true;
                continue;
            }

            if (flag && dp[j] != 0)
            {
                ansCount += dp[j] - countbefore;
                flag = false;
            }
        }
        ansVector.push_back(ansCount);
    }
    return ansVector;
}
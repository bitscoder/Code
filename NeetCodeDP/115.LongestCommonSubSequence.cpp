#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int rec(int l, int r, string s, string t, vector<vector<int>> &dp)
{
    if (r == t.size())
        return 1;
    else if (l == s.size())
        return 0;
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    if (s[l] == t[r])
    {
        dp[l][r] = rec(l + 1, r + 1, s, t, dp) + rec(l + 1, r, s, t, dp);
    }
    else
    {
        dp[l][r] = rec(l + 1, r, s, t, dp);
    }
    return dp[l][r];
}
int numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return rec(0, 0, s, t, dp);
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int back(string text1, string text2, int l, int r)
{
    if (l == text1.size() || r == text2.size())
        return 0;

    if (text1[l] == text2[r])
    {
        return 1 + back(text1, text2, l + 1, r + 1);
    }
    else
    {
        int left = back(text1, text2, l + 1, r);
        int right = back(text1, text2, l, r + 1);
        return max(left, right);
    }
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (text1[i] == text2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
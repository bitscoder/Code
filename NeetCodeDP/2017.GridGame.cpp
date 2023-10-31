#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
long long gridGame(vector<vector<int>> &grid)
{
    int n = grid[0].size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[1][n - 1] = grid[1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[1][i] += dp[1][i + 1];
    }
    dp[0][n - 1] += dp[1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        dp[0][i] += max(dp[1][i], dp[0][i + 1]);
    }

    int l = 0;
    int r = 0;
    grid[l][r] = 0;
    while (!(l == 1 && r == (n - 1)))
    {
        int nrow = l + 1;
        int ncol = r + 1;
        if (nrow <= 1 && ncol < n)
        {
            if (dp[nrow][r] < dp[l][ncol])
            {
                grid[l][ncol] = 0;
                r = ncol;
            }
            else
            {
                grid[nrow][r] = 0;
                l = nrow;
            }
        }
        else if (nrow <= 1)
        {
            grid[nrow][r] = 0;
            l = nrow;
        }
        else if (ncol < n)
        {
            grid[l][ncol] = 0;
            r = ncol;
        }
    }
    dp = vector<vector<int>>(2, vector<int>(n, 0));

    dp[1][n - 1] = grid[1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[1][i] += dp[1][i + 1];
    }
    dp[0][n - 1] += dp[1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        dp[0][i] += max(dp[1][i], dp[0][i + 1]);
    }
    return dp[0][0];
}
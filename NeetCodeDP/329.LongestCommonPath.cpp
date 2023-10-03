#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int dfs(int l, int r, vector<vector<int>> &matrix, vector<vector<int>> dp)
{
    if (l < 0 || r < 0 || l >= matrix.size() || r >= matrix[0].size())
        return 0;

    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int dim[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int nrow = l + dim[i][0];
        int ncol = r + dim[i][1];
        if (nrow >= 0 && ncol >= 0 && nrow < matrix.size() && ncol < matrix[0].size() && matrix[l][r] < matrix[nrow][ncol])
        {
            ans = max(1 + dfs(nrow, ncol, matrix, dp), ans);
        }
    }
    dp[l][r] = ans;
    return dp[l][r];
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ansMax = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -1)
            {
                dfs(i, j, matrix, dp);
            }
            ansMax = max(ansMax, dp[i][j]);
        }
    }
    return ansMax;
}
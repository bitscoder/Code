#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int returnMax(int l, int r, int n, int m, vector<vector<int>> &grid)
{
    if (l >= n || r >= m || l < 0 || r < 0 || grid[l][r] == 0)
    {
        return 0;
    }
    int ans = 0;
    int a = grid[l][r];
    grid[l][r] = 0;
    int dim[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; i++)
    {
        int ncol = l + dim[i][0];
        int nrow = r + dim[i][1];
        ans = max(ans, returnMax(ncol, nrow, n, m, grid));
    }
    grid[l][r] = a;
    return a + ans;
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, returnMax(i, j, n, m, grid));
        }
    }
    return ans;
}
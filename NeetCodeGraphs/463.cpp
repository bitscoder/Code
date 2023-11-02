#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class Solution
{
private:
    int dfs(vector<vector<int>> &grid, int n, int m, int r, int c, vector<vector<int>> &visited)
    {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0 || visited[r][c] == 1)
        {
            return 0;
        }
        int dim[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            int nrow = dim[i][0];
            int ncol = dim[i][1];
            if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m || grid[nrow][ncol] == 0)
                ans++;
        }
        visited[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = dim[i][0];
            int ncol = dim[i][1];
            ans += dfs(grid, n, m, r, c, visited);
        }
        return ans;
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return dfs(grid, n, m, i, j, visited);
                }
            }
        }
        return 0;
    }
};
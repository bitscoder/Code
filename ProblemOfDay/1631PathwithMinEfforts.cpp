#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<pair<int, int>> adjList[n * m];
    int dim[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nrow = i + dim[k][0];
                int ncol = j + dim[k][1];
                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0)
                    adjList[i * m + j].emplace_back(make_pair(nrow * m + ncol, abs(heights[i][j] - heights[nrow][ncol])));
            }
        }
    }
}
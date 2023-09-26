#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

int dfs(vector<vector<int>>& grid,int i, int j, int n, int m){
    if(i < 0|| j< 0 || i >= n || j >= m || grid[i][j] != 1){
        return -1;
    }
    grid[i][j] = 2;
    int max = -1;
    int down = dfs(grid, i+1, j, n, m);
    if(down > max)
        max = down;
    int east = dfs(grid, i, j+1, n, m);
    if(east > max)
        max = east;
    int west = dfs(grid, i-1, j, n, m);
    if(west > max)
        max = west;
    int up = dfs(grid, i, j-1, n, m);
    if(up > max)
        max = up;
    return max == -1? -1 : max++;
}
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ansMax = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0; j < m; j++ ){
            int max = -1;
            if(grid[i][j] == 2){
                int down = dfs(grid, i+1, j, n, m);
                if(down > max)
                    max = down;
                int east = dfs(grid, i, j+1, n, m);
                if(east > max)
                    max = east;
                int west = dfs(grid, i-1, j, n, m);
                if(west > max)
                    max = west;
                int up = dfs(grid, i, j-1, n, m);
                if(up > max)
                    max = up;
                max = max == -1 ? -1 : max++;
            }
            if(max > ansMax)
                ansMax = max;
        }
    }
    queue<pair<pair<int, int>, int>> bfsqueue;

    for(int i = 0;i<n;i++){
        for(int j = 0; j < m; j++ ){
            if(grid[i][j] == 1)
                bfsqueue.push({{i,j},0});
        }
    }
    int ans = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0, -1, 0, 1};
    while (!bfsqueue.empty())
    {
        int r = bfsqueue.front().first.first;
        int c = bfsqueue.front().first.second;
        int t = bfsqueue.front().second;
        ans = max(ans, t);
        bfsqueue.pop();
        for(int i =0;i<4;i++){
            int ncol = r + drow[i];
            int nrow = c + dcol[i];
            if(ncol >= 0 && ncol < n && nrow >= 0 && nrow < m && grid[ncol][nrow] == 1){
                bfsqueue.push({{ncol, nrow}, t + 1});
                grid[ncol][nrow] = 2;
            }
        }
    }
    


    for(int i = 0;i<n;i++){
        for(int j = 0; j < m; j++ ){
            if(grid[i][j] == 1)
                return -1;
        }
    }
    return ansMax;
}
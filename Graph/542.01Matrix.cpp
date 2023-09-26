#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> bfsqueue;
        vector<vector<int>> ansGrid( n , vector<int> (m, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0; j < m; j++ ){
                if(grid[i][j] == 0)
                    bfsqueue.push({{i,j},0});
                ansGrid[i][j] = 0;
            }
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while (!bfsqueue.empty())
        {
            int r = bfsqueue.front().first.first;
            int c = bfsqueue.front().first.second;
            int t = bfsqueue.front().second;
            bfsqueue.pop();
            for(int i =0; i<4; i++){
                int ncol = r + drow[i];
                int nrow = c + dcol[i];
                if(ncol >= 0 && ncol < n && nrow >= 0 && nrow < m && grid[ncol][nrow] == 1){
                    bfsqueue.push({{ncol, nrow}, t + 1});
                    ansGrid[ncol][nrow] = t + 1;
                    grid[ncol][nrow] = 0;
                }
            }
        }
        
        return ansGrid;
}
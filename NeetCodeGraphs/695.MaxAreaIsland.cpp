#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> adjList[], vector<int>& mem, int k){
    int ans = 0;
    for(int i = 0; i < adjList[k].size(); i++){
        if(mem[adjList[k][i]] == 0){
            mem[adjList[k][i]] = 1;
            ans += dfs(adjList, mem, adjList[k][i]);
        }
    }
    return ans + 1;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();


    // adjList 
    vector<int> adjList[m*n];
    int dim[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                cout<< "r" << endl;
                for(int k = 0; k<4; k++){
                    int nrow = i + dim[k][0];
                    int ncol = j + dim[k][1];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                        if(grid[nrow][ncol] == 1){
                            adjList[i * m + j].push_back(nrow * m + ncol);
                        }
                    }
                }
            }
        }
    }
    // memory vector
    vector<int> mem(m * n, 0);
    //
    int ans = 0;
 

    for(int i = 0; i < m*n; i++){
        if(mem[i] == 0 && grid[i/m][i%m] == 1){
            
            mem[i] = 1;
            ans = max(ans, dfs(adjList, mem, i));
        }
    }
    return ans;
}

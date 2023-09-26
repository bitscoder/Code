#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[], vector<int>& mem, int k){
    for(int i = 0; i < adjList[k].size(); i++){
        if(mem[adjList[k][i]] == 0){
            mem[adjList[k][i]] = 1;
            dfs(adjList, mem, adjList[k][i]);
        }
    }
    return;
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();


    // adjList 
    vector<int> adjList[m*n];
    int dim[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                cout<< "r" << endl;
                for(int k = 0; k<4; k++){
                    int nrow = i + dim[k][0];
                    int ncol = j + dim[k][1];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                        if(grid[nrow][ncol] == '1'){
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
        for(auto it : adjList[i])
            cout << it << " ";
        cout << endl;
    }

    for(int i = 0; i < m*n; i++){
        if(mem[i] == 0 && grid[i/m][i%m] == '1'){
            ans++;
            mem[i] = 1;
            dfs(adjList, mem, i);
        }
    }
    return ans;
}
/*
Input: grid = [
    0   1   2   3   4
  ["1","1","1","1","0"],
    5   6
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1*/

void bfs(vector<vector<int>>& helperVector, int k, int m,vector<int> adjList[]){
    queue<int> q;
    q.push(m);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        helperVector[cur/m][cur%m] = 1;
        for(int i : adjList[cur]){
            if(helperVector[i/m][i%m] == 0){
                q.push(i);
            }
        }
    }
    return;
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int sides[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<int> adjList[m * n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                for(int k = 0; k < 4; k++){
                    int nrow = i + sides[k][0];
                    int ncol = j + sides[k][1];
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1'){
                        adjList[i * m + j].emplace_back(nrow * m + ncol);
                    }
                }
            }
        }
    }
    vector<vector<int>> helperVector(n, vector<int>(m, 0));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(helperVector[i][j] == 0 && grid[i][j] == '1'){
                ans++;
                bfs(helperVector, i * m + j, m, adjList);
            }
        }
    }
    return ans;
}
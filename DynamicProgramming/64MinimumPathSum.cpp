#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int minPath(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& tapVector){
        
    if(i == n - 1 && j == m - 1) return grid[i][j];
    
    if(i >= n || j >= m || i < 0 || j < 0) return INT_MAX;

    if(tapVector[i][j] != 0) return tapVector[i][j];
    
    tapVector[i][j] =  grid[i][j] + min(minPath(grid, i + 1, j, n, m, tapVector), minPath(grid, i, j + 1, n, m, tapVector));
    return tapVector[i][j];
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> tapVector(n, vector<int>(m, 0));
    return minPath(grid, 0, 0, n, m, tapVector);
}
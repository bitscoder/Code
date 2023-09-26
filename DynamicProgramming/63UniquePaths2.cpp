#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int uniquePaths(int m, int n) {

    
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1] == 1) return 0;
    if(m == 1 && n == 1 && obstacleGrid[m-1][n-1] == 0) return 1;
    
    int arr[m][n];
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(obstacleGrid[m -1][i] == 1)
            flag = true;
        
        if(flag)
            arr[m - 1][i] = 0;
        else
            arr[m - 1][i] = 1;
    }
    flag = false;  
    for(int i = 0; i < m; i++){
        if(obstacleGrid[i][n - 1] == 1)
            flag = true;
        
        if(flag)
            arr[i][n - 1] = 0;
        else
            arr[i][n - 1]  = 1;
    }
    
    arr[m-1][n-1] = 0;

    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            if(obstacleGrid[i][j] == 1)
                arr[i][j] = 0;
            else
                arr[i][j] = arr[i+1][j] + arr[i][j+1];
        }
    }

    return arr[0][0]; 
}
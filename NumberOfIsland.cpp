#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // adjacency list 
    vector<int> adjList[n * m];

    int sumToDiduct = 0;

    for( int i =0;i< n;i++){
        for(int j =0; j<m; j++){
            if(grid[i][j] == 1){
                if(i-1 >= 0 && grid[i-1][j] ==1)
                    adjList[m*i+j].push_back((i-1) * m + j);
                
                if(j-1 >= 0 && grid[i][j-1] == 1)
                    adjList[m*i+j].push_back(i * m + j - 1);
                
                if(i+1 < n && grid[i+1][j] == 1)
                    adjList[m*i+j].push_back((i+1) * m + (j-1));

                if(j+1 < n && grid[i][j+1] == 1)
                    adjList[m*j+i].push_back(i * m + j + 1);
            }
            else{
                sumToDiduct++;
            }
        }
    }  
    int * keepTapArray = new int[n * m];
    int answer = 0;
    for(int i = 0; i < (n * m) ; i++){
        keepTapArray[i] = 1;
        dfs(keepTapArray, adjList, i);
        answer++;
    }
    return answer - sumToDiduct;

}
void dfs(int* keepTapArray, vector<int>  adjList[], int currentNode){
    for(auto it : adjList[currentNode]){
        if(!keepTapArray[it]){
            dfs(keepTapArray, adjList, currentNode);
        }
        
    }

}
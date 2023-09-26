#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie();
}
void dfs(vector<vector<char>>& board, int i, int j){
    int dim[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    for(int i = 0; i < 4; i++){
        int nrow = dim[i][0] + i;
        int ncol = dim[i][1] + j;
        if(ncol >= 0 && nrow >= 0 && nrow < board.size() && ncol < board[0].size()){
            if(board[nrow][ncol] == 'O'){
                board[nrow][ncol] = 'T';
                dfs(board, nrow, ncol);
            }
        }
    }
    return;
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m =  board[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                board[i][j] = 'T';
                dfs(board, i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            
            if(board[i][j] == 'T')
                board[i][j] = 'O';
        }
    }
}

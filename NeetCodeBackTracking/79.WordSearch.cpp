#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}
bool backtrack(vector<vector<char>>& board, string word, int i, int k, int l, vector<vector<int>>& tap){
    if(i == word.size()) return true;

    int row[4] = {1,0,0,-1};
    int col[4] = {0,1,-1,0};

    for(int j = 0; j < 4; j++){
        int nrow = k + row[j];
        int ncol = l + col[j];
        if(nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size() && word[i] == board[nrow][ncol] && tap[nrow][ncol] == 0){
            cout << nrow << " " << ncol << endl;
            tap[nrow][ncol] = 1;
            if(backtrack(board, word, i+1, nrow, ncol, tap)) return true;
            tap[nrow][ncol] = 0;
        }
    }
    return false;
}
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> tap(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == word[0]){
                tap[i][j] = 1;
                if(backtrack(board, word, 1, i, j, tap))
                    return true;
                tap[i][j] = 0; 
            }
        }
    }
    return false;
}
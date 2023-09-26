#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ansHelperGrid(n * m  , vector<int> (4, 0));
        vector<vector<int>> tapVector(n , vector<int> (m, 0));

        for(int i= 0; i< n; i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'X')
                    tapVector [i][j] = 1;
                else
                    tapVector [i][j] = 0;
            }
        }
        for(int i= 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(tapVector[i][j] == 0){
                    dfs(board, i, j, n, m, ansHelperGrid, tapVector);
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    int sum = 0;
                    for(int k = 0;k < 4; k++){
                        sum += ansHelperGrid[m * i + j][k];
                        cout<< ansHelperGrid [m * i + j][k] << m * i + j << endl;
                    }
                    if(sum == 4){
                        board[i][j] = 'X';
                    }
                    
                }
                cout<< tapVector[i][j];
                cout<< endl;
            }
        }

    }
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m,vector<vector<int>>& ansHelperGrid,
        vector<vector<int>>& tapVector){
        
        tapVector[i][j] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for(int k = 0; k < 4; k++){
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            cout<< nrow << " Ruturaj "<< ncol <<endl;
            if(nrow >= 0  && nrow < n && ncol >= 0 && ncol < m ){
                if(board[nrow][ncol] == 'X'){
                    ansHelperGrid [m * i + j][k] = 1;
                    cout<< ansHelperGrid [m * i + j][k] << m * i + j << endl;
                }
            }
        }
        for(int k = 0; k < 4; k++){
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if(nrow >= 0  && nrow < n && ncol >= 0 && ncol < m ){
                if(ansHelperGrid [m * i + j ][k] != 1){
                    
                    if(tapVector[nrow][ncol]!=0){
                        dfs(board, nrow, ncol, n, m, ansHelperGrid, tapVector);
                    }
                    int sum = 0; 
                    for(int l = 0;l< 4; l++){
                        sum += ansHelperGrid [m * nrow + ncol ][k];
                    }
                    if(sum == 4){
                        ansHelperGrid [m * i + j ][k] = ansHelperGrid [m * nrow + ncol ][k];
                    }
                }
            }
        }
    }
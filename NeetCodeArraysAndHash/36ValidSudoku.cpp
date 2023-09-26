#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
    cout<<(int)'1'<<endl;
}
bool isValidSudoku(vector<vector<char>>& board) {
        int arr [9][2] = {{-1,-1},{-1,0},{0,-1},{1,0},{0,1},{1,1},{1,-1},{-1,1},{0,0}};
        int points [9][2] = {{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
        for(int i = 0; i < 9; i++){
            vector<int> row(9, 0);
            vector<int> col(9, 0);
            vector<int> grp(9, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    row[(int)board[i][j] - 49]++;
                    if(row[(int)board[i][j]- 49]  == 2) return false;
                }
                if(board[j][i] != '.'){
                    col[(int)board[j][i] - 49]++;
                    if(col[(int)board[j][i]- 49]  == 2) return false;
                }
                //cout<< points[i][1] + arr[j][1]<< points[i][2] + arr[j][2] << endl;
                if(board[points[i][0] + arr[j][0]][points[i][1] + arr[j][1]] != '.'){
                    grp[(int)board[points[i][0] + arr[j][0]][points[i][1] + arr[j][1]] - 49]++;
                    if(grp[(int)board[points[i][0] + arr[j][0]][points[i][1] + arr[j][1]] - 49] == 2) return false;
                }
            }
        }
        
        return true;}
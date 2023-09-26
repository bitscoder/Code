#include<bits/stdc++.h>
using namespace std;

bool checkQ(vector<string>& result, int k, int l, int n){
    for(int i = 0; i < n; i++){
        if(result[k][i] == 'Q')return false;
        if(result[i][l] == 'Q')return false;
    }
    int row[4] = {-1, 1, -1, 1};
    int col[4] = {-1, 1, 1, -1};
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 4; j++){
            int nrow = k + row[j] * i;
            int ncol = l + col[j] * i;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && result[nrow][ncol] == 'Q'){
                return false;
            }
        }
    }
    return true;
}
void backTracking( int start, int n, vector<string>& result, vector<vector<string> >& ansVector){
    if(start == n)ansVector.emplace_back(result);

    for(int i = 0; i < n; i++){
        if(checkQ(result, start, i, n)){
            result[start][i] = 'Q';
            backTracking(start + 1, n,result, ansVector);
            result[start][i] = '.';
        }
    }
} 
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ansVector;
    if(n == 1){
        vector<string> k;
        k.push_back("Q");
        ansVector.push_back(k);
        return ansVector;
    }
    string temp = "";
    for(int i = 0; i < n; i++){
        temp += ".";
    }
    vector<string> result(n, temp);
    backTracking(0, n, result, ansVector);
    return ansVector;
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
    int n = 9;
    vector<vector<string> > ans = solveNQueens(n);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    } 
}
/*
    Q . . . {-1, 1, -1, 1}
    . Q . . {-1, 1, 1, -1}

*/


#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int rec(int r, int c, int n, vector<vector<vector<int>>>& dp){
        if(n == 0){
            return 1;
        }
        int dim[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}};
        if(dp[r][c][n] != 0){
            return dp[r][c][n];
        }
        int ansCount = 0;
        for(int i = 0; i < 8; i++){
            int nrow = dim[i][0] + r;
            int ncol = dim[i][1] + c;
            if (nrow >= 0 && nrow < 4 && ncol >= 0 && ncol < 3 && (nrow != 3 || ncol == 1))
            {
                ansCount =  ( ansCount + rec(nrow, ncol, n - 1, dp)) % mod;
            }
        }
        dp[r][c][n] = ansCount;
        return dp[r][c][n];
    }
public:
    int knightDialer(int n)
    {
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, 0)));
        
        int ansCount = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(i != 3 || j == 1){
                    ansCount =  (ansCount + rec(i, j, n - 1, dp)) % mod;
                }
            }
        }
        return ansCount;

    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n = 3131; // Replace with the desired value of n
    vector<vector>
    int result = sol.knightDialer(n);
    cout << "Result: " << result << endl;

    return 0;
}

// 1 2 3
// 4 5 6
// 7 8 9
// * 0 #



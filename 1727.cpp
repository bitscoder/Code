#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                if(matrix[i][j] != 0){
                    matrix[i][j] += matrix[i - 1][j];
                }
            }   
        }



        for(int i = 0; i < n; i++){
            sort(matrix[i].begin(), matrix[i].end());

        }

    }
};
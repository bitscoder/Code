#include<bits/stdc++.h>
using namespace std;
bool binary(vector<vector<int>>&  nums, int target, int i, int j, int n){
    if(i < j){
        int m = (j + i)/2;
        if(nums[m/n][m%n] == target){
            return true;
        }else if(nums[m/n][m%n] > target)
        return binary (nums, target, i, m, n);
        else
            return binary(nums, target, m+1, j, n);
    }else return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    return binary(matrix, target, 0, m * n, n);
}

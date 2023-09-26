#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
        
    return binary(nums, target, 0, nums.size());
}
int binary(vector<int>& nums, int target, int i, int j){
    if(i < j){
        int m = (j + i)/2;
        if(nums[m] == target){
            return m;
        }else if(nums[m] > target)
        return binary (nums, target, i, m);
        else
            return binary(nums, target, m+1, j);
    }else return -1;
}
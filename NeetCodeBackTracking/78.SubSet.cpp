#include<bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}

vector<vector<int>> subsets(vector<int>& nums) {
    return backTracking(nums, 0, nums.size());
}

vector<vector<int>> backTracking(vector<int>& nums, int i, int n){
    if(i == n){
        vector<vector<int>> ans;
        vector<int> k;
        ans.emplace_back(k);
        return ans;
    } 
    vector<vector<int>> ans = backTracking(nums, i + 1, n);
    vector<vector<int>> rans;
    for(vector<int> d : ans){
        rans.push_back(d);
        d.push_back(nums[i]);
    }
    return rans;
}
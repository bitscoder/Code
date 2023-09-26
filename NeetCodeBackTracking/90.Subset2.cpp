#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}
void backTracking(vector<int>& nums, int start, int n, vector<int>& current, vector<vector<int>>& result){
    if(start == n){
        result.push_back(current);
        return;
    } 
    current.push_back(nums[start]);
    backTracking(nums, start+1, n, current, result);
    current.pop_back();

    while(start <= n && nums[start]==0)

        backTracking(nums, start+1, n, current, result);
    
    return ;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    sort(nums.begin(), nums.end()); // Sort candidates to handle duplicates
    vector<vector<int>> result;
    vector<int> current;
    backTracking(nums, 0, nums.size(), current, result);
    return result;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{

}
bool canJump(vector<int>& nums) {
    int k = 1;
    for(int i = nums.size() - 2; i >= 0; i--){
        if(k <= nums[i])
            k = 1;
        else
            k++;
    }
    if(k == 1)return true;
    else return false;
}
// JumpGame 2
// [2,3,1,1,4]

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){
        int ans = INT_MAX;
        for(int j = 0; j < i; i++){
            if((i - j) <= nums[j])
                ans = min(dp[j] + 1, ans);
        }
        dp[i] = ans;
    }
    return dp[n - 1];
}
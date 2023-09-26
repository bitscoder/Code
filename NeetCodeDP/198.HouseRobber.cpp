#include <bits/stdc++.h>
using namespace std;

/*Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.*/
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)return  nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = nums[0];

    for(int i = 2; i < n; i++){
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
}
//213. House Robber II
/*Input: nums = [1,2,3]
Output: 3
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.*/
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)return  nums[0];
    if(n == 2) return max(nums[0],nums[1]);
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[1], dp[0]);

    for(int i = 2; i < n - 1; i++)
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    
    vector<int> dp1 (n, 0);
    dp1[1] = nums[1];
    dp1[2] = max(nums[2], dp1[1]); 
    
    for(int i = 3; i < n; i++)
        dp1[i] = max(nums[i] + dp1[i - 2], dp1[i - 1]);
    
    return max(dp1[n - 1], dp[n - 2]);    
}
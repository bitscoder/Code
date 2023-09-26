#include <bits/stdc++.h>
using namespace std;

/*Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0*/
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for(int i : coins){
        dp[i] = 1;
    }
    for(int i = 1; i <= amount; i++){
        int cur = INT_MAX;
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                cur = min(cur, dp[i - coins[j]]);
            }
        }
        dp[i] = cur == INT_MAX ? -1 : cur + 1;
    }
    return dp[amount];
}
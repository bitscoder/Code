#include <bits/stdc++.h>
using namespace std;
/*Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Input
[-2,3,-4]
Output
3
Expected
24*/
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > dp(n, vector<int> (3, 0));
    dp[0][0] = INT_MIN;// not taking
    dp[0][1] = nums[0];// smallest
    dp[0][2] = nums[0];// largest
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = max(nums[i] * dp[i-1][1], nums[i] * dp[i-1][2]);
        dp[i][2] = min(nums[i] * dp[i-1][1], nums[i] * dp[i-1][2]);
    }    

    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
int main(){
    vector<int> a;
    a.push_back(-2);
    a.push_back(3);
    a.push_back(-4);
    cout << maxProduct(a);
}
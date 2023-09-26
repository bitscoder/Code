#include <bits/stdc++.h>
using namespace std;
/*Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

    1 -> 1
    2 -> {1, [1]} {2}



*/
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    int n = nums.size();
    for(int i = 1; i <= target; i++ ){
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(i - nums[j] >=0){
                ans += dp[i - nums[j]];
            }else{
                break;
            }
        }
        dp[i] = ans;
    }
    return dp[target];
}
int main(){
    vector<int> k;
    k.push_back(1);
    k.push_back(2);
    k.push_back(3);
    cout << combinationSum4(k, 4);

}

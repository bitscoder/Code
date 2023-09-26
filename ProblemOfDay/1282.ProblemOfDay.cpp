#include<bits/stdc++.h>
using namespace std;
/*Wrong Answer
Details 
Input
[4,10,4,3,8,9]
Output
4
Expected
3
*/
int lengthOfLIS(vector<int>& nums) { 
    int n = nums.size();

    vector<int> dp(n, 0);
    dp[0] = 1;
    int result = 1;
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }  
        result = max(result, dp[i]); 
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(10);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(8);
    nums.push_back(9);

    cout << lengthOfLIS(nums);
}
/*
    Input: groupSizes = [3,3,3,3,3,1,3]
    Output: [[5],[0,1,2],[3,4,6]]
    Explanation: 
    The first group is [5]. The size is 1, and groupSizes[5] = 1.
    The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
    The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
    Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
*/
/*vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> um;
    int n = groupSizes.size();
    for(int i = 0; i < n; i++){
        um[groupSizes[i]].emplace_back(i);
    }
    for(auto pa : um){
        for(int i = 0; i < pa.second.size()/pa.first; i++){
            vector<int> temp;
            for(int j = 0; j < pa.first; j++){
                temp.emplace_back(pa.second[j + i * pa.first]);
            }
            ans.emplace_back(temp);
        }

    }
    return ans;
}

int maxIncreasingGroups(vector<int>& usageLimits) {
    int n = usageLimits.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(usageLimits[i] >= usageLimits[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;       
}*/
/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

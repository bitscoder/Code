#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int bac(int curSum, int l, vector<int> &nums, int target, unordered_map<pair<int, int>, int> um)
{
    if (l == nums.size() && curSum == target)
        return 1;
    else if (l == nums.size())
        return 0;
    if (um.find({l, curSum}) != um.end())
    {
        return um[{l, curSum}];
    }
    um[{l, curSum}] = bac(curSum + nums[l], l + 1, nums, target, um) + bac(curSum - nums[l], l + 1, nums, target, um);

    return um[{l, curSum}];
}
int findTargetSumWays(vector<int> &nums, int target)
{
    unordered_map<pair<int, int>, int> um;
    return bac(nums[0], 1, nums, target, um);
}
/*
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/
/*
    sum
    i == size() && sum == target
        return 1
    else i == size()
        return 0


*/
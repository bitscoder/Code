#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool rec(int i, int currSum, vector<int> &nums)
{
    if (currSum == 0)
        return true;
    if (i == nums.size())
        return false;
    bool with = false;
    if (nums[i] <= currSum)
        with = rec(i + 1, currSum - nums[i], nums);
    bool without = rec(i + 1, currSum, nums);
    return with | without;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto i : nums)
    {
        sum += i;
    }
    if (sum % 2 == 1)
        return false;
    unordered_set<int> dp;
    dp.insert(0);
    dp.insert(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        int n = dp.size();
        unordered_set<int>::iterator it;
        for (int j = 0; j < n; j++)
        {
            dp.insert(nums[i] + *it);
            it++;
        }
        if (dp.find(sum / 2) != dp.end())
            return true;
    }
    return false;
}
int back(string text1, string text2, int l, int r)
{
    if (l == text1.size() || r == text2.size())
        return 0;

    if (text1[l] == text2[r])
    {
        return 1 + back(text1, text2, l + 1, r + 1);
    }
    else
    {
        int left = back(text1, text2, l + 1, r);
        int right = back(text1, text2, l, r + 1);
        return max(left, right);
    }
}
int longestCommonSubsequence(string text1, string text2)
{
    return back(text1, text2, 0, 0);
}
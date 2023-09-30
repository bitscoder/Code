#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int findMaximumXOR(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            ans = max(ans, nums[i] ^ nums[j]);
        }
    }
    return ans;
}
vector<int> sortArrayByParity(vector<int> &nums)
{
    vector<int> evenArray;
    vector<int> oddArray;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & 1)
            oddArray.push_back(nums[i]);
        else
            oddArray.push_back(nums[i]);
    }
    oddArray.insert(oddArray.end(), evenArray.begin(), evenArray.end());
    return oddArray;
}
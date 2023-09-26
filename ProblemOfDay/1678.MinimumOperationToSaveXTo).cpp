#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// giving me tle

int rec(vector<int> &nums, int l, int k, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
    if (k < l)
        return -1;

    int left = rec(nums, l + 1, k, x - nums[l]);
    int right = rec(nums, l, k - 1, x - nums[k]);

    if (left == -1 && right == -1)
        return -1;
    if (left == -1)
        return right + 1;
    if (right == -1)
        return left + 1;
    return min(left, right) + 1;
}
int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();
    int ans = rec(nums, 0, n - 1, x);
    return ans;
}
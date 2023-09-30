#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool isMonotonic(vector<int> &nums)
{
    int n = nums.size();
    bool inc = true;
    bool dec = true;
    for (int i = 1; i < n; i++)
    {
        if (!(nums[i - 1] <= nums[i]))
            inc = false;
        if (!(nums[i - 1] >= nums[i]))
            dec = false;
    }
    return inc | dec;
}
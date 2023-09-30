#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool find132pattern(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return false;
    int min1 = nums[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > min1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > min1 && nums[j] < nums[i])
                    return true;
            }
        }
        min1 = min(min1, nums[i]);
    }
    return false;
}
//[3,1,4,2]

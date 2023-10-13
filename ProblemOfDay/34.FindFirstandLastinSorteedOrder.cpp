#include <bits/stdc++.h>
using namespace std;
void binary(vector<int> &nums, int target, int l, int r, vector<int> &ansVector)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            ansVector.push_back(mid);
            binary(nums, target, l, mid - 1, ansVector);
            binary(nums, target, mid + 1, r, ansVector);
        }
        else if (nums[mid] > target)
        {
            binary(nums, target, l, mid - 1, ansVector);
        }
        else
        {
            binary(nums, target, mid + 1, r, ansVector);
        }
    }
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    int right = -1;
    while (l <= r)
    {
        cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            right = mid;
            l = mid + 1;
        }
        else if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    l = 0;
    r = nums.size() - 1;
    int left = -1;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            left = mid;
            r = mid - 1;
        }
        else if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    vector<int> ansVector;
    ansVector.push_back(left);
    ansVector.push_back(right);
    return ansVector;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
    */
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);

    int target = 8;
    vector<int> ans = searchRange(nums, target);
    cout << "ruturaj";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

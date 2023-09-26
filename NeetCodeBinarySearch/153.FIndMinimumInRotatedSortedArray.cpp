#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    return binary(nums, 0, nums.size() - 1);
}

int binary(vector<int>& nums, int i, int j) {
    if (i < j) {
        int m = i + (j - i) / 2; // This avoids integer overflow

        if (nums[m] > nums[j])
            return binary(nums, m + 1, j);
        else
            return binary(nums, i, m);
    } else {
        return nums[i];
    }
}

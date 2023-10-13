#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
/*
    1345. Jump Game IV
    Hard

    3615

    125

    Add to List

    Share
    Given an array of integers arr, you are initially positioned at the first index of the array.

    In one step you can jump from index i to index:

    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.
    Return the minimum number of steps to reach the last index of the array.

    Notice that you can not jump outside of the array at any time.



    Example 1:

    Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
    Output: 3
    Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
    Example 2:

    Input: arr = [7]
    Output: 0
    Explanation: Start index is the last index. You do not need to jump.
*/
int minJumps(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dpleft(n, 0);

    for (int i = 1; i < n; i++)
    {
        dpleft[i] = 1 + dpleft[i - 1];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] == arr[i])
            {
                dpleft[i] = min(dpleft[i], dpleft[j] + 1);
            }
        }
    }
}
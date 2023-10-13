#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int findKthPositive(vector<int> &arr, int k)
{
    // vector<int> ansVector;

    int temp = 0;
    for (int curr : arr)
    {
        for (int i = temp + 1; i < curr; i++)
        {
            k--;
            if (k == 0)
                return i;
        }
        temp = curr;
    }
    for (int i = temp + 1; i < 1000; i++)
    {
        k--;
        if (k == 0)
            return i;
    }
    return -1;
}
#include <bits/stdc++.h>
using namespace std;
int integerBreak(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int curMax = 0;
        for (int j = 1; j < i; j++)
        {
            curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
        }
        dp[i] = curMax;
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << integerBreak(10) << endl;
}

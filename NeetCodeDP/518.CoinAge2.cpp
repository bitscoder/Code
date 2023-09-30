#include <bits/stdc++.h>

using namespace std;
int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;
    for (int i = 2; i <= amount; i++)
    {
        for (auto j : coins)
        {
            if ((i - j) >= 0)
                dp[i] = dp[i] + dp[i - j];
        }
        cout << endl;
    }

    return dp[amount];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    cout << change(5, coins);
}
/*Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

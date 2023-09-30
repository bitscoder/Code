#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int back(vector<int> &prices, int flag, int currBuy, int l)
{
    if (l == prices.size())
        return 0;
    if (flag % 3 == 0)
    {
        int with = back(prices, flag + 1, prices[l], l + 1);
        int without = back(prices, flag, 0, l + 1);
        return max(with, without);
    }
    else if (flag % 3 == 1)
    {
        return max(prices[l] - currBuy + back(prices, flag + 1, 0, l + 1), back(prices, flag, 0, l + 1));
    }
    else
        return back(prices, flag + 1, 0, l + 1);
}

int maxProfit(vector<int> &prices)
{
    return back(prices, 0, 0, 0);
}
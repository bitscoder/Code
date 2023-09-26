#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> price(n, INT_MAX);
    price[src] = 0;
    for (int i = 0; i < k + 1; i++)
    {
        vector<int> tempPrice = price;
        for (int j = 0; j < flights.size(); i++)
        {
            if (tempPrice[flights[j][0]] == INT_MAX)
                continue;
            if (tempPrice[flights[j][0]] + flights[j][1] < tempPrice[flights[j][1]])
                tempPrice[flights[j][1]] = tempPrice[flights[j][0]] + flights[j][1];
        }
        price = tempPrice;
    }
    return price[dst] == INT_MAX ? -1 : price[dst];
}
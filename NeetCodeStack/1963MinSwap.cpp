#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int minSwaps(string s)
{
    int n = s.size();
    int maxclosing = 0;
    int balancecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[')
        {
            balancecount--;
        }
        else
        {
            balancecount++;
            maxclosing = max(maxclosing, balancecount);
        }
    }
    return maxclosing % 2 == 1 ? (maxclosing + 1) / 2 : maxclosing / 2;
}
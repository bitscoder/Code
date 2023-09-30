#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int rec(int l, int r, string s)
{
    if (l < 0 || r >= s.size() || s[l] != s[r])
        return 0;
    else
        return 1 + rec(l - 1, r - 1, s);
}

int countSubstrings(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        ans += rec(i, i, s);
        ans += rec(i, i + 1, s);
    }
    return ans;
}
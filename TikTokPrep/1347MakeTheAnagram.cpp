#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int minSteps(string s, string t)
{
    vector<int> shelper(26, 0);
    vector<int> thelper(26, 0);
    int n = s.size();
    for (int i; i < n; i++)
    {
        shelper[s[i] - 'a']++;
        thelper[t[i] - 'a']++;
    }
    int carry = 0;
    for (int i = 0; i < 26; i++)
    {
        if (thelper[i] < shelper[i])
            carry += (shelper[i] - thelper[i]);
    }
    return carry;
}
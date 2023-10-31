#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int> findArray(vector<int> &pref)
{
    int n = pref.size();
    vector<int> ans(n);
    ans.push_back(pref[0]);
    for (int i = 1; i < n; i++)
    {
        ans.push_back(pref[i] ^ pref[i - 1]);
    }
    return ans;
}
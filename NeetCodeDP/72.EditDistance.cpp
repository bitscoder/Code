#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int bac(int l, int r, string word1, string word2)
{
    if (r == word2.size())
    {
        return word1.size() - l;
    }
    else if (l == word1.size())
        return INT_MAX;
    int ans = INT_MAX;
    if (word1[l] == word2[r])
        ans = min(ans, bac(l + 1, r + 1, word1, word2));
    else
    {
        int value1 = bac(l + 1, r + 1, word1, word2);
        int value2 = bac(l, r + 1, word1, word2);
        int value3 = bac(l + 1, r, word1, word2);
        ans = min({1 + (value1 == INT_MAX ? INT_MAX - 1 : value1),
                   1 + (value2 == INT_MAX ? INT_MAX - 1 : value2),
                   1 + (value3 == INT_MAX ? INT_MAX - 1 : value3)});
    }
    return ans;
}
int minDistance(string word1, string word2)
{
    return bac(0, 0, word1, word2);
}
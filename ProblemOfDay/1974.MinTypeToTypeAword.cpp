#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int minTimeToType(string word)
{
    int curPointer = 'a' - 'a';
    int len = word.size();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        int direct = abs(word[i] - curPointer);
        int it = word[i] - 'a';
        int indirect = 0;
        if (it > curPointer)
        {
            indirect += (25 - it);
            indirect += (curPointer - 0);
            indirect++;
        }
        else
        {
            indirect += (25 - curPointer);
            indirect += (it);
            indirect++;
        }
        ans += min(direct, indirect);
        ans++;
    }
    return ans;
}
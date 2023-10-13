#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool backspaceCompare(string s, string t)
{
    stack<char> helperStack1;
    stack<char> helperStack2;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            if (helperStack1.size() == 0)
                return false;
            else
                helperStack1.pop();
        }
        else
        {
            helperStack1.push(s[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '#')
        {
            if (helperStack2.size() == 0)
                return false;
            else
                helperStack2.pop();
        }
        else
        {
            helperStack2.push(t[i]);
        }
    }
    if (helperStack1.size() == helperStack2.size())
    {
        int k = helperStack1.size();
        while (k == 0)
        {
            if (helperStack1.top() != helperStack2.top())
                return false;
            helperStack1.pop();
            helperStack2.pop();
            k--;
        }
    }
    else
    {
        return false;
    }
    return true;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int numberOfWeakCharactersw(vector<vector<int>> &properties)
{

    unordered_map<int, int> um;
    int max_attack = INT_MIN;
    int min_attack = INT_MAX;
    int n = properties.size();
    for (int i = 0; i < n; i++)
    {
        um[properties[i][0]] = properties[i][1];
        max_attack = max(max_attack, properties[i][0]);
        min_attack = min(min_attack, properties[i][0]);
    }
    int max_def = INT_MIN;
    int ansCount = 0;
    for (int i = max_attack; i >= 1; i++)
    {
        if (um.find(i) == um.end())
        {
            continue;
        }
        if (um[i] < max_def)
        {
            ansCount++;
        }
        max_def = max(max_def, um[i]);
    }
    return ansCount;
}
static bool check(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int numberOfWeakCharacters(vector<vector<int>> &properties)
{

    sort(properties.begin(), properties.end(), check);
    int ansCount = 0;
    int curAttack = properties[properties.size() - 1][0];
    int maxdef = properties[properties.size() - 1][0];
    for (int i = properties.size() - 2; i >= 0; i++)
    {
        if (curAttack == properties[i][0])
        {
            continue;
        }
        if (properties[i][1] < maxdef)
        {
            ansCount++;
        }
        maxdef = max(maxdef, properties[i][1]);
    }
    return ansCount;
}
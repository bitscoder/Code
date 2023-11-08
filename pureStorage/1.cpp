#include <bits/stdc++.h>
using namespace std;
void findDouble(vector<int> helperVector)
{
    int n = helperVector.size();
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        um[helperVector[i]]++;
    }
    vector<int> ansVector;
    for (int i = 0; i < n; i++)
    {
        if (um[2 * helperVector[i]] == 1)
        {
            ansVector.push_back(helperVector[i]);
        }
    }
    sort(ansVector.begin(), ansVector.end());
    for (int i = 0; i < ansVector.size(); i++)
    {
        cout << ansVector[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 7 17 11 1 23
    vector<int> helperVector;
    helperVector.push_back(1);
    helperVector.push_back(1);
    helperVector.push_back(2);

    findDouble(helperVector);
}

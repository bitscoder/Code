#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> positveHelper;
    vector<int> negativeHelper;

    for (auto i : asteroids)
    {
        positveHelper.push_back(i);
        negativeHelper.push_back(i);
    }
    sort(positveHelper.begin(), positveHelper.end(), greater<int>());
    sort(negativeHelper.begin(), negativeHelper.end());

    int i = 0;
    int j = 0;
    int n = positveHelper.size();
    int m = negativeHelper.size();
    vector<int> ansVector;
    while (i < n && j < m)
    {
        if (positveHelper[i] > abs(negativeHelper))
        {
        }
    }
}
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> helperStack;

    for ()
    {
    }
}
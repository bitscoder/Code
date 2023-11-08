#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        vector<int> helperVector;
        int n = dist.size();
        for (int i = 0; i < n; i++)
        {
            helperVector.push_back(dist[i] / speed[i]);
        }
        int cost = 1;
        sort(helperVector.begin(), helperVector.end());
        for (int i = 1; i < n; i++)
        {
            if (helperVector[i] - 1 <= 0)
            {
                cost++;
            }
        }
        return cost;
    }
};
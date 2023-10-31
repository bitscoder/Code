#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int maximumScore(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityHelper;
    for (int i = 0; i <)
    {
    }
}

int minimumSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> helperVectorLeft(n, INT_MAX);
    int curMin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        helperVectorLeft[i] = curMin;
        curMin = min(curMin, nums[i]);
    }
    vector<int> helperVectorRight(n, INT_MAX);
    curMin = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        helperVectorRight[i] = curMin;
        curMin = min(curMin, nums[i]);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (helperVectorLeft[i] < nums[i] && helperVectorRight[i] < nums[i])
        {
            ans = min(ans, helperVectorLeft[i] + helperVectorRight[i] + nums[i]);
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
void back(stack<int> helperStack, )
{
    int reminder = helperVector[i] % curMin;
    int reminder2 = helperVector[i] % (curMin + 1);
    if (reminder == 0)
    {
        for (int k = 0; k < helperVector[i] / curMin; k++)
        {
            helperStack.push(curMin);
        }
    }
    else if (reminder2 == 0)
    {
        for (int k = 0; k < helperVector[i] / (curMin + 1); k++)
        {
            helperStack.push(curMin + 1);
        }
    }
}

int minGroupsForValidAssignment(vector<int> &nums)
{
    unordered_map<int, int> helperMap;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        helperMap[nums[i]]++;

    vector<int> helperVector;
    for (auto it = helperMap.begin(); it != helperMap.end(); ++it)
        helperVector.push_back(it->second);

    sort(helperVector.begin(), helperVector.end());

    int curMin = helperVector[0];

    stack<int> helperStack;

    for (int i = 1; i < helperVector.size(); i++)
    {
        if (helperVector[i] == curMin || helperVector[i] == curMin + 1)
        {
            helperStack.push(helperVector[i]);
        }
        else
        {
        }
    }

    return helperStack.size();
}
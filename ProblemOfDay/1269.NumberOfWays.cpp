#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int back(int steps, int arrLen, int i)
{
    if (steps == 0 && i == 0)
        return 1;
    if (steps == 0 && i != 0)
        return 0;
    if (i == arrLen || i < 0)
        return 0;
    else
        back(steps - 1, arrLen, i) + back(steps - 1, arrLen, i - 1) + back(steps - 1, arrLen, i + 1);
}
int numWays(int steps, int arrLen)
{
    return back(steps, arrLen, 0);
}

vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
{
    int n = nums.size();
    vector<int> ansVector;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference)
            {
                ansVector.push_back(i);
                ansVector.push_back(j);
                return ansVector;
            }
        }
    }
    ansVector.push_back(-1);
    ansVector.push_back(-1);
    return ansVector;
}
// 100011001
string shortestBeautifulSubstring(string s, int k)
{
    int n = s.size();
    string ansString = s;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int currCount = s[i] == '1' ? 1 : 0;
        string curString = s.substr(i, 1);
        if (k == 1 && currCount)
        {
            return "1";
        }
        for (int j = i + 1; j < n; j++)
        {
            currCount += s[j] == '1' ? 1 : 0;
            curString = curString + s.substr(j, 1);
            if (k == currCount && curString.size() <= ansString.size())
            {
                if (curString.size() == ansString.size() && stoi(curString) < stoi(ansString))
                {
                    curString == ansString;
                }
                else
                {
                    curString = ansString;
                }
                flag = true;
            }
        }
    }
    if (flag)
    {
        return ansString;
    }
    else
    {
        return "";
    }
}
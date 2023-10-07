#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool winnerOfGame(string colors)
{
    int countA = 0;
    int countB = 0;
    int n = colors.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
        {
            countA++;
        }
        if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
        {
            countB++;
        }
    }
    if (countA > countB)
        return true;
    else
        return false;
}
/*
Input: colors = "AAABABB"
Output: true
Explanation:
AAABABB -> AABABB
Alice moves first.
She removes the second 'A' from the left since that is the only 'A' whose neighbors are both 'A'.

Now it's Bob's turn.
Bob cannot make a move on his turn since there are no 'B's whose neighbors are both 'B'.
Thus, Alice wins, so return true.
*/

long findValuation(long reqArea, vector<long> area, vector<long> price)
{
    // outlier remove
    int n = area.size();
    vector<int> outlier;
    for (int i = 0; i < n; i++)
    {
        int pricehelper = 0;
        int count = 0;
        vector<int> match;
        for (int j = 0; j < n; j++)
        {
            if (i != j && area[i] == area[j])
            {
                pricehelper += price[j];
                count++;
                match.push_back(price[j]);
            }
        }
        if (count != 0)
        {
            float average = (float)pricehelper / count;
            float sum = 0;
            for (int i : match)
            {
                sum += (i - average) * (i - average) / count;
            }
            float miu = sqrt(sum);
            if (abs(price[i] - average) > 3 * miu)
            {
                outlier.push_back(i);
            }
        }
    }
}

int findBestPath(int n, int m, int startRow, int startColumn, int endRow, int endColumn, vector<int> monsterRow, vector<int> monsterColumn)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[startRow][startColumn] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (find(monsterRow.begin(), monsterRow.end(), i) != monsterRow.end() && find(monsterColumn.begin(), monsterColumn.end(), j) != monsterColumn.end())
            {
                dp[i][j] = 0;
                continue;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            else if (i - 1 >= 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (j - 1 >= 0)
            {
                dp[i][j] = dp[i][j - 1];
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[endRow][endColumn];
}
int numIdenticalPairs(vector<int> &nums)
{
    vector<int> helperVector(101, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        helperVector[nums[i]]++;
    }
    int ans = 0;
    for (int i = 0; i <= 101; i++)
    {
        ans += (nums[i] + 1) * (nums[i]) / 2;
    }
    return ans;
}
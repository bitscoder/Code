#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int count(int l, int r, vector<vector<int>> &grid, int n, vector<vector<int>> &visit, vector<vector<int>> &dp)
{
    if ((l == (n - 1)) && (r == (n - 1)))
    {
        if (grid[l][r] == 1)
            return INT_MAX;
        else
            return 1;
    }

    if (l < 0 || l >= n || r < 0 || r >= n || grid[l][r] == 1 || visit[l][r] != 0)
        return INT_MAX;
    if (dp[l][r] != 0)
        return dp[l][r];
    visit[l][r] = 1;
    int curAns = INT_MAX;
    int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int i = 0; i < 8; i++)
    {
        int nrow = l + dir[i][0];
        int ncol = r + dir[i][1];
        int forword = count(nrow, ncol, grid, n, visit, dp);
        curAns = min(curAns, ((forword == INT_MAX) ? INT_MAX : 1 + forword));
    }
    visit[l][r] = 0;
    dp[l][r] = curAns;
    return dp[l][r];
}
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> visit(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return count(0, 0, grid, n, visit, dp);
}

/*
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.
*/
int dfs(int count, string &curString, unordered_map<char, vector<char>> um)
{
    if (count == 0)
        return 1;
    vector<char> res;
    if (curString.size() == 0)
    {
        res = um['0'];
    }
    else
    {
        res = um[curString.size() - 1];
    }
    int ansCount = 0;
    for (int i = 0; res.size(); i++)
    {
        curString += res[i];
        ansCount += dfs(count - 1, curString, um);
        curString.pop_back();
    }
    return ansCount;
}

int countVowelPermutation(int n)
{
    unordered_map<char, vector<char>> um;
    um['a'].push_back('e');
    um['e'].push_back('a');
    um['e'].push_back('i');
    um['i'].push_back('a');
    um['i'].push_back('e');
    um['i'].push_back('o');
    um['i'].push_back('u');
    um['o'].push_back('i');
    um['o'].push_back('u');
    um['u'].push_back('a');
    um['0'] = {'a', 'e', 'i', 'o', 'u'};
    string curString = "";
    return dfs(n, curString, um);
}
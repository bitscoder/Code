#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int maxProduct(string s)
{
}
int kthGrammar(int n, int k)
{
    int cur = 0;
    int l = 0;
    int r = pow(2, (n - 1));
    for (int i = 1; i < n; i++)
    {
        int mid = (l + r) / 2;
        if (k <= mid)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
            cur = cur ^ 1;
        }
    }
    return cur;
}

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, int>> helperQueue;

        helperQueue.push({root, 0});
        int sum1 = 0;
        int sum2 = 0;
        while (!helperQueue.empty())
        {
            int row = helperQueue.front().second;
            while (row = helperQueue.front().second)
            {
                auto cur = helperQueue.front();
                helperQueue.pop();
                if (row % 2 == 1)
                {
                    sum1 += cur.first->val;
                }
                else
                {
                    sum2 += cur.first->val;
                }
                if (cur.first->left == nullptr)
                {
                    helperQueue.push({cur.first->left, row + 1});
                }
                if (cur.first->right == nullptr)
                {
                    helperQueue.push({cur.first->right, row + 1});
                }
            }
        }
        return max(sum1, sum2);
    }
};

long long mostPoints(vector<vector<int>> &questions)
{
    int n = questions.size();
    vector<int> dp(n, 0);
    dp[n - 1] = questions[n - 1][0];
    for (int i = n - 2; i >= 0; i--)
    {
        int k = i + questions[i][1] + 1;
        if (k < n)
        {
            dp[i] = max(dp[k] + questions[i][0], dp[i + 1]);
        }
        else
        {
            dp[i] = questions[i][0];
        }
    }
    return dp[0];
}
class Solution
{
private:
    void back(string s, int l, string &helperString, vector<string> &ansVector)
    {
        if (l == s.size())
        {
            ansVector.push_back(helperString);
        }
        for (int i = 1; i <= 3; i++)
        {
            string curString = s.substr(l, i);
            int cur = stoi(curString);
            if (cur <= 255 && cur >= 0)
            {
                if (helperString.size() != 0)
                {
                    helperString += ".";
                    helperString += curString;
                    back(s, l + i, helperString, ansVector);
                    for (int j = 0; j < i; j++)
                    {
                        helperString.pop_back();
                    }
                    helperString.pop_back();
                }
                else
                {
                    helperString += curString;
                    back(s, l + i, helperString, ansVector);
                    for (int j = 0; j < i; j++)
                    {
                        helperString.pop_back();
                    }
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ansVector;
        string helperString;
        back(s, 0, helperString, ansVector);
        return ansVector;
    }
};
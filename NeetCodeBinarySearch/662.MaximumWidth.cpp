#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<tuple<TreeNode *, int, int>> helperQueue;
        helperQueue.push({root, 1, 0});
        int ansMax = 0;
        while (!helperQueue.empty())
        {
            int row = get<2>(helperQueue.front());
            int l = INT_MAX;
            int r = INT_MIN;
            while (get<2>(helperQueue.front()) == row)
            {
                auto cur = helperQueue.front();
                l = min(l, get<1>(cur));
                r = max(r, get<1>(cur));
                helperQueue.pop();
                if (get<0>(cur)->left != nullptr)
                {
                    helperQueue.push({get<0>(cur)->left, (get<1>(cur) - 1) * 2 + 1, get<2>(cur) + 1});
                }
                if (get<0>(cur)->right != nullptr)
                {
                    helperQueue.push({get<0>(cur)->right, (get<1>(cur) - 1) * 2 + 2, get<2>(cur) + 1});
                }
            }
            ansMax = max(ansMax, r - l + 1);
        }
        return ansMax;
    }
};
int dfs(int curSum, int l, int target, int total, int n, vector<vector<int>> &dp, vector<int> &stones)
{
    if (curSum >= total || l == n)
    {
        return abs(curSum - (target - curSum));
    }
    if (dp[l][curSum] != -1)
    {
        return dp[l][curSum];
    }
    dp[l][curSum] = min(dfs(curSum + stones[l], l + 1, target, total, n, dp, stones), dfs(curSum, l + 1, target, total, n, dp, stones));
    return dp[l][curSum];
}

int lastStoneWeightII(vector<int> &stones)
{
    int sum = 0;
    int n = stones.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + stones[i];
    }
    int total = (sum % 2 == 1) ? (sum / 2 + 1) : sum / 2;
    vector<vector<int>> dp(n, vector<int>(total + 1, -1));
    return dfs(0, 0, sum, total, n, dp, stones);
}

int minimumDifference(vector<int> &nums, int k)
{
    if (k == 0 || k == 1)
        return 0;
    int diff = INT_MAX;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // 1, 2, 3, 4
    for (int i = k - 1; i < n; i++)
    {
        diff = min(diff, (nums[i] - nums[i - k + 1]));
    }
    return diff;
}
long long fact(int n)
{
    if (n == 1)
        return 1;

    return n * fact(n - 1);
}
long long interchangeableRectangles(vector<vector<int>> &rectangles)
{
    int n = rectangles.size();
    unordered_map<double, int> um;
    for (int i = 0; i < n; i++)
        um[(double)rectangles[i][0] / rectangles[i][1]]++;

    long long ans = 0;
    for (auto dic : um)
    {
        if (dic.second == 1)
            continue;
        else
            ans += fact(dic.second - 1);
    }
    return ans;
}

string gcdOfStrings(string str1, string str2)
{
    int n = (str2.size() > str1.size()) ? 1 : 1;
    string ansString = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (str1.find(str2.substr(i, (j - i + 1))) != string::npos)
            {
                ansString = str2.substr(i, (j - i + 1)).size() > ansString.size() ? str2.substr(i, (j - i + 1)) : ansString;
            }
        }
    }
    return ansString;
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<pair<TreeNode *, int>> helperQueue;
    helperQueue.push({root, 0});
    vector<vector<int>> ansVector;
    if (root == nullptr)
        return ansVector;
    while (!helperQueue.empty())
    {
        int row = helperQueue.front().second;
        vector<int> curAns;
        while (row == helperQueue.front().second)
        {
            auto cur = helperQueue.front();
            helperQueue.pop();
            curAns.push_back(cur.first->val);
            if (cur.first->left != nullptr)
                helperQueue.push({cur.first->left, cur.second + 1});
            if (cur.first->right != nullptr)
                helperQueue.push({cur.first->right, cur.second + 1});
        }
        ansVector.push_back(curAns);
    }
    return ansVector;
}
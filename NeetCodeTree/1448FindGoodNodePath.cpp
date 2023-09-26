#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int dfs(TreeNode *root, int &currMax)
{
    if (root == nullptr)
        return 0;
    int ans = 0;
    if (currMax < root->val)
    {
        ans = 1;
        currMax = root->val;
    }
    int leftAns = dfs(root->left, currMax);
    int rightAns = dfs(root->right, currMax);
    return leftAns + rightAns + ans;
}
int goodNodes(TreeNode *root)
{
    int currMax = INT_MIN;
    return dfs(root, currMax);
}
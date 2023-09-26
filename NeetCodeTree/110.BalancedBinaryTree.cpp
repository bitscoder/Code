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
pair<bool, int> Balanced(TreeNode *root)
{
    if (root == NULL)
        return pair<bool, int>(true, -1);

    pair<bool, int> ansLeft = Balanced(root->left);
    pair<bool, int> ansRight = Balanced(root->right);

    return pair<bool, int>(ansLeft.first * ansRight.first * (abs(ansLeft.second - ansRight.second) <= 1), max(ansLeft.second + 1, ansRight.second + 1));
}
bool isBalanced(TreeNode *root)
{
    return Balanced(root).first;
}
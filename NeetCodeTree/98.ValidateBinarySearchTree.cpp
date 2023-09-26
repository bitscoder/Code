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
static void inorder(TreeNode *root, vector<int> &helperVector)
{
    if (root == nullptr)
        return;
    inorder(root->left, helperVector);
    helperVector.push_back(root->val);
    inorder(root->right, helperVector);
    return;
}
bool isValidBST(TreeNode *root)
{
    vector<int> helperVector;
    inorder(root, helperVector);
    int n = helperVector.size();
    for (int i = 1; i < n; i++)
    {
        if (helperVector[i - 1] >= helperVector[i])
            return false;
    }
    return true;
}
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
void invert(TreeNode *root, TreeNode *&ansNode)
{
    if (root == NULL)
    {
        ansNode = NULL;
        return;
    }

    ansNode = new TreeNode(root->val);
    invert(root->right, ansNode->left);
    invert(root->left, ansNode->right);
}

TreeNode *invertTree(TreeNode *root)
{
    TreeNode *ansNode; // Initialize ansNode to nullptr
    invert(root, ansNode);
    return ansNode;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
static void inorder(TreeNode *root, vector<int> &helperVector)
{
    if (root == nullptr)
        return;
    inorder(root->left, helperVector);
    helperVector.push_back(root->val);
    inorder(root->right, helperVector);
    return;
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> helperVector;
    inorder(root, helperVector);
    sort(helperVector.begin(), helperVector.end());
    return helperVector[k - 1];
}
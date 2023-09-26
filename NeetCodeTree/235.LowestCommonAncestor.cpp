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
bool check(TreeNode *root, TreeNode *p)
{
    if (root == NULL)
        return false;

    if (root->val == p->val)
        return true;
    if (check(root->left, p))
        return true;
    if (check(root->right, p))
        return true;

    return false;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;
    if ((check(root->left, p) || root->val == p->val) && (check(root->right, q) || root->val == q->val))
        return root;
    if ((check(root->left, q) || root->val == q->val) && (check(root->right, p) || root->val == p->val))
        return root;
    TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

    return leftAns == NULL ? rightAns : leftAns;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //[2,1]
    // 2
    // 1
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(1);

    TreeNode *ans = lowestCommonAncestor(root, p, q);
    cout << ans->val << endl;
}

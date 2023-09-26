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
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL)
        return false;
    else if (q == NULL)
        return false;

    if (p->val != q->val)
        return false;
    else
    {
        return isSameTree(p->left, q->left) * isSameTree(p->right, q->right);
    }
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL && subRoot == NULL)
        return true;
    else if (root == NULL)
        return false;
    else if (subRoot == NULL)
        return true;
    ;

    if (isSameTree(root, subRoot))
        return true;
    if (isSubtree(root->left, subRoot))
        return true;
    if (isSubtree(root->right, subRoot))
        return true;
    return false;
}
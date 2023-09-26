#include<bits/stdc++.h>
using namespace std;
    int ans = INT_MIN;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int maxPathSum(TreeNode* root) {
    if(root ==  NULL) return 0;
    
    int leftMax = max(maxPathSum(root->left), 0);
    int rightMax = max(maxPathSum(root->right), 0);

    ans = max(ans, leftMax + rightMax + root->val);
    return root->val + max(leftMax, rightMax);
}
int maxPathSum(TreeNode* root) {
    if(root ==  NULL) return 0;
    
    int leftMax = max(maxPathSum(root->left), 0);
    int rightMax = max(maxPathSum(root->right), 0);

    ans = max(ans, leftMax + rightMax + root->val);
    return root->val + max(leftMax, rightMax);
}

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}

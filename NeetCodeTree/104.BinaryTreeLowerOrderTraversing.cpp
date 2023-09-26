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
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ansVector;
    queue<pair<TreeNode *, int>> helperQueue;
    helperQueue.push({root, 0});

    while (!helperQueue.empty())
    {
        pair<TreeNode *, int> currNode = helperQueue.front();
        helperQueue.pop();
        ansVector[currNode.second].push_back(currNode.first->val);
        if (currNode.first->left != NULL)
            helperQueue.push({currNode.first->left, currNode.second + 1});
        if (currNode.first->right != NULL)
            helperQueue.push({currNode.first->right, currNode.second + 1});
    }

    return ansVector;
}
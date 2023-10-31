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
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<pair<TreeNode *, int>> queue;
        queue.push(make_pair(root, 0));
        vector<int> ansVector;
        while (!queue.empty())
        {
            int row = queue.front().second;
            int curMax = INT_MIN;
            while (queue.front().second == row)
            {
                auto cur = queue.front();
                queue.pop();
                curMax = max(cur.first->val, curMax);
                if (cur.first->left != nullptr)
                {
                    queue.push({cur.first->left, cur.second + 1});
                }
                if (cur.first->right != nullptr)
                {
                    queue.push({cur.first->right, cur.second + 1});
                }
            }
            ansVector.push_back(curMax);
        }
        return ansVector;
    }
};
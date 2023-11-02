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
private:
    tuple<int, int, int> dfs(TreeNode *root)
    {

        tuple<int, int, int> left = {0, 0, 0};
        if (root->left != nullptr)
        {
            left = dfs(root);
        }
        tuple<int, int, int> right = {0, 0, 0};
        if (root->left != nullptr)
        {
            right = dfs(root);
        }
        tuple<int, int, int> ans = {get<0>(left) + get<0>(right),
                                    get<1>(left) + get<1>(right),
                                    get<2>(left) + get<2>(right) + 1};
        if (root->val == (get<1>(left) + get<1>(right) + root->val) / (get<2>(left) + get<2>(right) + 1))
        {
            get<0>(ans)++;
        }
        return ans;
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return get<0>(dfs(root));
    }
};
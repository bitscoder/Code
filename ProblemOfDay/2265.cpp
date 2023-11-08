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
/*
    Input: target = [1,3], n = 3
    Output: ["Push","Push","Pop","Push"]
    Explanation: Initially the stack s is empty. The last element is the top of the stack.
    Read 1 from the stream and push it to the stack. s = [1].
    Read 2 from the stream and push it to the stack. s = [1,2].
    Pop the integer on the top of the stack. s = [1].
    Read 3 from the stream and push it to the stack. s = [1,3].
*/
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int t = 0;
        vector<string> ansVector;
        for (int i = 1; i <= n && t < target.size(); i++)
        {
            if (target[t] == i)
            {
                ansVector.push_back("Push");
                t++;
            }
            else
            {
                ansVector.push_back("Push");
                ansVector.push_back("Pop");
            }
        }
        return ansVector;
    }
};
class Solution
{
private:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int r, int c, int n, int m, vector<vector<int>> &helperVector)
    {
        if (r < 0 || c < 0 || r >= n || c >= m || grid2[r][c] == 0 || helperVector[r][c] == 1)
        {
            return true;
        }
        helperVector[r][c] = 1;
        if (grid2[r][c] == 1 && grid1[r][c] == 0)
        {
            return false;
        }
        int dim[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dim[i][0];
            int ncol = c + dim[i][1];
            if (!dfs(grid1, grid2, nrow, ncol, n, m, helperVector))
            {
                return false;
            }
        }
        return true;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> helperVector(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (helperVector[i][j] == 0 && grid2[i][j] == 1 && dfs(grid1, grid2, i, j, n, m, helperVector))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

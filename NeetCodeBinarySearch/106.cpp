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
// inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
class Solution
{
public:
    void dfs(TreeNode *root, vector<int> &inorder, vector<int> &postorder, int &l, int r)
    {
        if (r == -1 || l < 0)
            return;
        root->val = postorder[r];
        if (inorder[l] == postorder[r])
        {
            l = l - 2;
            return;
        }
        dfs(root->left, inorder, postorder, l, r - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size() - 1;
        int m = postorder.size() - 1;
        TreeNode *root = new TreeNode(postorder[m]);
        dfs(root, inorder, postorder, n, m);
        return root;
    }
};

int findKOr(vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        int ccount = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] % 2 == 1)
            {
                ccount++;
            }
            nums[j] = nums[j] / 2;
        }
        if (ccount >= k)
            count += ccount;
    }
    return count;
}

long long minSum(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    pair<int, int> cur = {0, 0};
    for (int i = 0; i < n; i++)
    {
        cur.first += nums1[i];
        if (nums1[i] == 0)
        {
            cur.second++;
        }
    }
    n = nums2.size();
    pair<int, int> cur1 = {0, 0};
    for (int i = 0; i < n; i++)
    {
        cur1.first += nums2[i];
        if (nums2[i] == 0)
        {
            cur1.second++;
        }
    }
    int ans = 0;
    if (cur.first > cur1.first)
    {
        if (cur.second > cur1.second)
        {
            return cur.first + cur.second;
        }
        else
        {
            if ((cur.first + cur.second) < (cur1.first + cur1.second))
            {
                return cur1.first + cur1.second;
            }
            else
            {
                return cur.first + cur.second;
            }
        }
    }
    else
    {
    }
}
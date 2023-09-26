#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> check(vector<int> &maxHeights, int index)
{
    int currHighest = maxHeights[index];
    pair<long long, long long> ans = make_pair(0, 0);
    for (int i = index; i >= 0; i--)
    {
        // cout << ans << currHighest << maxHeights[i] << endl;
        ans.first += min(currHighest, maxHeights[i]);
        currHighest = min(currHighest, maxHeights[i]);
    }
    currHighest = maxHeights[index];
    for (int i = index + 1; i < maxHeights.size(); i++)
    {
        ans.second += min(currHighest, maxHeights[i]);
        currHighest = min(currHighest, maxHeights[i]);
    }
    // cout << ans << endl;
    return ans;
}

long long maximumSumOfHeights(vector<int> &maxHeights)
{
    pair<long long, long long> currAns = check(maxHeights, 0);

    long long ans = currAns.first + currAns.second;
    for (int i = 1; i < maxHeights.size(); i++)
    {
        currAns.second = currAns.second - min(maxHeights[i - 1], maxHeights[i]);
        currAns.first = currAns.first + maxHeights[i] - maxHeights[i] < maxHeights[i - 1] ? (maxHeights[i - 1] - maxHeights[i]) * i : 0;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //[5,3,4,1,1]
    vector<int> height;
    height.push_back(5);
    height.push_back(3);
    height.push_back(4);
    height.push_back(1);
    height.push_back(1);
    cout << maximumSumOfHeights(height);
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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty())
    {
        return nullptr;
    }
    int rootVal = preorder[0];
    TreeNode *root = new TreeNode(rootVal);
    int rootIndex = 0;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == rootVal)
        {
            rootIndex = i;
            break;
        }
    }
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
    vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
    vector<int> rightPreorder(preorder.begin() + rootIndex + 1, preorder.end());
    vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);
    return root;
}
string maximumOddBinaryNumber(string s)
{
    int CountOne = 0;
    for (char i : s)
        if (i == '1')
            CountOne++;

    for (int i = 0; i < s.size(); i++)
    {
        if (i < CountOne - 1)
            s[i] = '1';
        else
            s[i] = '0';
    }
    s[s.size() - 2] = 1;
    return s;
}

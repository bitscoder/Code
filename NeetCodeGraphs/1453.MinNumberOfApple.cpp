#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<int> adjList[n];
        vector<int> visited(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][1]].push_back(edges[i][0]);
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        int ans = dfs(adjList, 0, hasApple, visited);
        return ans == 0 ? ans : ans - 2;
    }

private:
    int dfs(vector<int> adjList[], int l, vector<bool> &hasApple, vector<int> &visited)
    {
        if (visited[l] == 1)
        {
            return 0;
        }
        int ans = 0;
        int n = adjList[l].size();
        visited[l] == 1;
        for (int i = 0; i < n; i++)
            ans += dfs(adjList, adjList[l][i], hasApple, visited);
        if ((hasApple[l] || ans != 0))
        {
            ans += 2;
        }
        cout << l << " " << ans << endl;
        return ans;
    }
};

//  Definition for a binary tree node.
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return root;
        if (root->val >= low && root->val <= high)
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        else
        {
            TreeNode *left = trimBST(root->left, low, high);
            TreeNode *right = trimBST(root->right, low, high);
            if (left == nullptr)
                root = right;
            else
                root = left;
        }
        return root;
    }
};
class Solution
{
public:
    string decodeString(string s)
    {
        int n = s.size();
        stack<char> helperStack;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ']')
            {
                string curString = "";
                while (helperStack.top() != '[')
                {
                    curString = helperStack.top() + curString;
                    helperStack.pop();
                }
                helperStack.pop();
                string curentNumber = "";
                while (!helperStack.empty() && (helperStack.top() >= '0' || helperStack.top() <= '9'))
                {
                    curentNumber = helperStack.top() + curentNumber;
                    helperStack.pop();
                }
                string ansString = "";
                for (int i = 0; i < stoi(curentNumber); i++)
                {
                    ansString += curString;
                }
                for (int i = 0; i < ansString.size(); i++)
                {
                    helperStack.push(ansString[i]);
                }
            }
            else
            {
                helperStack.push(s[i]);
            }
        }
        string ans = "";
        while (!helperStack.empty())
        {
            ans = helperStack.top() + ans;
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
class TreeNod
{
public:
    TreeNod *children[10];
    char val;
    TreeNod(char x)
    {
        for (int i = 0; i < 10; i++)
            children[i] = NULL;
        val = x;
    }
};
class Solution
{
public:
    void dfs(TreeNod *curNode, int i, string word)
    {
        if (curNode->children[word[i] - '0'] == NULL)
            curNode->children[word[i] - '0'] = new TreeNod(word[i]);
        if (word.size() - 1 == i)
            return;
        else
            dfs(curNode->children[word[i] - '0'], i + 1, word);
        return;
    }
    void bfs(TreeNod *curNode, string temp, vector<int> &ans)
    {
        if (curNode == NULL)
            return;
        ans.push_back(stoi(temp + curNode->val));
        for (int i = 0; i < 10; i++)
        {
            bfs(curNode->children[i], temp + curNode->val, ans);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        TreeNod *root = new TreeNod('0');
        // 28 -> 1, 2, 3
        for (int i = 1; i <= n; i++)
        {
            TreeNod *itrNode = root;
            dfs(itrNode, 0, to_string(i));
        }
        vector<int> ans;
        for (int i = 0; i < 10; i++)
        {
            bfs(root->children[i], "", ans);
        }
        return ans;
    }
};
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }

    // Take the first string as the initial prefix
    string prefix = strs[0];

    for (int i = 1; i < strs.size(); ++i)
    {
        int j = 0;
        // Compare each character in the prefix with the corresponding character in the current string
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
        {
            j++;
        }

        // Update the prefix to the common prefix so far
        prefix = prefix.substr(0, j);

        // If the prefix becomes empty, there is no common prefix
        if (prefix.empty())
        {
            break;
        }
    }

    return prefix;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.lexicalOrder(13);
    // flower,flow,flight
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    cout << longestCommonPrefix(strs);
}

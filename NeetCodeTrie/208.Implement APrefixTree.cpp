#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class TreeNode
{
public:
    TreeNode *children[26];
    bool isWordComplete;
    TreeNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isWordComplete = false;
    }
};
class Trie
{
public:
    TreeNode *root;
    Trie()
    {
        root = new TreeNode();
    }
    void dfs(TreeNode *curNode, int i, string word)
    {
        if (curNode->children[word[i] - 'a'] == NULL)
        {
            curNode->children[word[i] - 'a'] = new TreeNode();
        }
        if (word.size() - 1 == i)
        {
            curNode->children[word[i] - 'a']->isWordComplete = true;
            return;
        }
        else
        {
            dfs(curNode->children[word[i] - 'a'], i + 1, word);
        }
        return;
    }
    void insert(string word)
    {
        TreeNode *currNode = root;
        dfs(currNode, 0, word);
    }

    bool search(string word)
    {
        TreeNode *currNode = root;
        for (char s : word)
        {
            if (currNode->children[s - 'a'] == NULL)
            {
                return false;
            }
            else
                currNode = currNode->children[s - 'a'];
        }
        return currNode->isWordComplete;
    }

    bool startsWith(string prefix)
    {
        TreeNode *currNode = root;
        for (char s : prefix)
        {
            if (currNode->children[s - 'a'] == NULL)
            {
                return false;
            }
            else
                currNode = currNode->children[s - 'a'];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
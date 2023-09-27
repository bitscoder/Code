#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class TreeNod
{
public:
    TreeNod *children[26];
    bool isWordComplete;
    TreeNod()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isWordComplete = false;
    }
};
class WordDictionary
{
public:
    TreeNod *root;
    WordDictionary()
    {
        root = new TreeNod();
    }

    void addWord(string word)
    {
        TreeNod *currNode = root;
        for (auto s : word)
        {
            if (currNode->children[s - 'a'] == NULL)
            {
                currNode->children[s - 'a'] = new TreeNod();
            }
            currNode = currNode->children[s - 'a'];
        }
        currNode->isWordComplete = true;
    }
    bool dfs(TreeNod *currNode, int i, string word)
    {
        if (word[i] == '.')
        {
            bool currAns = false;
            if (i == word.size() - 1)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (currNode->children[j] != NULL)
                    {
                        currAns = currAns | currNode->children[j]->isWordComplete;
                    }
                }
                return currAns;
            }
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (currNode->children[j] != NULL)
                    {
                        currAns = currAns | dfs(currNode->children[j], i + 1, word);
                    }
                }
                return currAns;
            }
        }
        else
        { //
            if (currNode->children[word[i] - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                if (i == word.size() - 1)
                {
                    return currNode->children[word[i] - 'a']->isWordComplete;
                }
                else
                {
                    return dfs(currNode->children[word[i] - 'a'], i + 1, word);
                }
            }
        }
    }
    bool search(string word)
    {
        TreeNod *curNode = root;
        return dfs(root, 0, word);
    }
};
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
class Solution
{
private:
    void dfs(TreeNod *currNode, string &ansWord, vector<string> &ansVector, int count)
    {
        if (currNode->isWordComplete && count != 0)
        {
            count--;
            ansVector.push_back(ansWord);
            return;
        }
        else if (count == 0)
        {
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            if (currNode->children[i] != NULL)
            {
                ansWord += (char)(i + 'a');
                dfs(currNode->children[i], ansWord, ansVector, count);
            }
        }
        return;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        TreeNod *root = new TreeNod();
        for (auto word : products)
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

        vector<vector<string>> ans;
        string cur = "";
        for (int i = 0; i < searchWord.size(); i++)
        {
            cur += searchWord[i];
            vector<string> tempAns;
            TreeNod *currNode = root;
            bool flag = true;
            for (auto s : cur)
            {
                if (currNode->children[s - 'a'] != NULL)
                {
                    currNode = currNode->children[s - 'a'];
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                dfs(currNode, cur, tempAns, 3);
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};

bool isAlienSorted(vector<string> &words, string order)
{
    unordered_map<char, int> um;
    for (int i = 0; i < 26; i++)
    {
        um[order[i]] = i;
    }
    vector<string> helperVector;

    for (int i = 0; i < words.size(); i++)
    {
        string tempAns = "";
        for (auto s : words[i])
        {
            tempAns += s;
        }
        helperVector.push_back(tempAns);
    }
    vector<string> sortedVector = helperVector;
    sort(sortedVector.begin(), sortedVector.end());

    for (int i = 0; i < sortedVector.size(); i++)
    {
        if (sortedVector[i] != helperVector[i])
            return false;
    }
    return true;
}
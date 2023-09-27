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
    TreeNod *children[10];
    TreeNod()
    {
        for (int i = 0; i < 10; i++)
        {
            children[i] = NULL;
        }
    }
};
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        TreeNod *root = new TreeNod();
        TreeNod *itrNode = root;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                itrNode->children[j] = new TreeNod();
            }
        }
    }
};
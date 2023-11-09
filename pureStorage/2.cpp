#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void raceFail(vector<vector<int>> dataVector)
{
    string s = "I am in library";
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
    }

    while (getline(ss, word, ' '))
    {
    }
}

int countHomogenous(string s)
{
    unordered_map<int, int> um;
    int n = s.size();
    char cur = s[0];
    int count = 1;
    int cuCount = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == cur)
        {
            cuCount++;
            count += cuCount;
        }
        else
        {

            cur = s[i];
            cuCount = 1;
        }
    }
    return count;
}
// 4
// 4
// 3
// 2
// 1
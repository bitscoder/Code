#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
static bool check(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}
vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
{
    int m = flowers.size();
    vector<int> startVector;
    vector<int> endVector;
    for (int i = 0; i < m; i++)
    {
        startVector.push_back(flowers[i][0]);
        endVector.push_back(flowers[i][1]);
    }

    sort(startVector.begin(), startVector.end());
    sort(endVector.begin(), endVector.end());

    int n = people.size();
    vector<int> ansVector(n, 0);
    int count = 0;
    int l = 0;
    int r = 0;
    vector<pair<int, int>> peopleVector;
    for (int i = 0; i < n; i++)
    {
        peopleVector.push_back({people[i], i});
    }
    sort(peopleVector.begin(), peopleVector.end(), check);
    for (int i = 0; i < n; i++)
    {
        while (l < m && startVector[l] <= peopleVector[i].first)
        {
            count++;
            l++;
        }
        while (r < m && endVector[r] < peopleVector[i].first)
        {
            count--;
            r++;
        }
        ansVector[peopleVector[i].second] = count;
    }
    return ansVector;
}
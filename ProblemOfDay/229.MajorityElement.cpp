#include <bits/stdc++.h>
using namespace std;

static bool check(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int maxDis(vector<int> &a, vector<int> &b, int k)
{
    int n = a.size();
    map<int, int> um;
    for (int i : a)
    {
        um[i]++;
    }

    // Convert the map to a vector of pairs and sort
    vector<pair<int, int>> um_vec(um.begin(), um.end());
    sort(um_vec.begin(), um_vec.end(), check);

    vector<bool> visited(b.size(), false);
    int ansCount = 0;
    int uniCount = 0;

    for (int i : b)
    {
        if (um[i] == 0)
            uniCount++;
    }

    for (auto it = um_vec.begin(); it != um_vec.end(); ++it)
    {
        int curAns = 0;
        if (it->second == 1)
        {
            ansCount += 1;
        }
        else
        {
            if (it->second > uniCount)
            {
                ansCount += min(uniCount, k);
                break;
            }
            else
            {
                ansCount += min(it->second, k);
                k = it->second >= k ? 0 : k - it->second + 1;
                uniCount = uniCount - it->second + 1;
            }
        }
        if (k == 0)
            break;
    }

    return ansCount;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // a = 1, 1, 4,5,5 b = 4,4,3,1,5 k = 2
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    vector<int> b;
    b.push_back(4);
    b.push_back(4);
    b.push_back(3);
    b.push_back(1);
    b.push_back(5);
    cout << maxDis(a, b, 2) << endl;
}
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> um;
    for (int i : nums)
    {
        um[i]++;
    }
    int n = nums.size() / 3;
    vector<int> ansVector;
    for (auto i : um)
    {
        if (i.second > n)
        {
            ansVector.push_back(i.first);
        }
    }
    return ansVector;
}

// akuna prep
#include <bits/stdc++.h>
using namespace std;

static bool check(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int maxDis(vector<int> &a, vector<int> &b, int k)
{
    int n = a.size();
    map<int, int> um;
    for (int i : a)
    {
        um[i]++;
    }

    // Convert the map to a vector of pairs and sort
    vector<pair<int, int>> um_vec(um.begin(), um.end());
    sort(um_vec.begin(), um_vec.end(), check);

    vector<bool> visited(b.size(), false);
    int ansCount = 0;
    int uniCount = 0;

    for (int i : b)
    {
        if (um[i] == 0)
            uniCount++;
    }
    // cout << uniCount;
    bool flag = false;
    for (auto it = um_vec.begin(); it != um_vec.end(); ++it)
    {
        cout << it->first << " " << it->second << " " << uniCount << " " << k << endl;
        if (flag)
        {
            ansCount++;
            continue;
        }
        if (it->second == 1)
        {
            ansCount += 1;
        }
        else
        {
            // 4, 3, 8
            //
            // 4, 8, 3
            // 4, 8,
            if (it->second - 1 == uniCount)
            {
                if (k >= uniCount)
                {
                    ansCount += it->second;
                }
                else
                {
                    ansCount += min(uniCount, k);
                }
                flag = true;
                continue;
            }
            else if ((it->second - 1) > uniCount)
            {
                ansCount += min(uniCount, k);
                flag = true;
                continue;
            }
            else
            {
                if (k >= (it->second - 1))
                {
                    ansCount += it->second;
                    k = k - it->second + 1;
                    uniCount = uniCount - it->second + 1;
                }
                else
                {
                    ansCount += k;
                    flag = true;
                }
            }
        }
    }
    return ansCount;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // a = 1, 1, 4,5,5 b = 4,4,3,1,5 k = 2
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    vector<int> b;
    b.push_back(4);
    b.push_back(4);
    b.push_back(3);
    b.push_back(1);
    b.push_back(5);
    cout << maxDis(a, b, 2) << endl;
}
static bool check(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int getMinMachines(int start_count, int *start, int end_count, int *end)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < start_count; i++)
    {
        vec.push_back({start[i], end[i]});
    }
    sort(vec.begin(), vec.end(), check);
    int curmin = vec[0].second;
    int ans = 1;
    for (int i = 1; i < start_count; i++)
    {
        if (curmin > vec[i].first)
        {
            ans++;
            curmin =
        }
    }
}
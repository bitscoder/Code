#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class Graph
{
private:
    vector<pair<int, int>> *adjList;
    int ver;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        adjList = new vector<pair<int, int>>[n];
        ver = n;
        for (auto i : edges)
        {
            adjList[i[0]].push_back({i[1], i[2]});
        }
    }
    void addEdge(vector<int> edge)
    {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        vector<int> dist(ver, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>()> pq;
        pq.push({0, node1});
        dist[node1] = 0;
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            for (auto it : adjList[index])
            {
                int edgeWeight = it.first;
                int node = it.second;

                if (dis + edgeWeight < dist[node])
                {
                    dist[node] = dis + edgeWeight;
                    pq.push({dist[node], node});
                }
            }
        }
        return dist[node2];
    }
};

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        unordered_map<string, vector<int>> adjList;
        for (int i = 0; i < access_times.size(); i++)
        {
            adjList[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        vector<string> ansString;
        for (auto it : adjList)
        {
            int n = it.second.size();
            if (n < 3)
                continue;
            else
            {
                sort(it.second.begin(), it.second.end());

                for (int i = 0; i < n; i++)
                {
                    int threshold = (it.second[i] / 100 + (((it.second[i] % 100 + 60) / 60) == 1 ? 1 : 0)) * 100 + ((it.second[i] % 100 + 60) % 60);
                    if (i + 2 < n && it.second[i + 2] < threshold)
                    {
                        ansString.push_back(it.first);
                        break;
                    }
                }
            }
        }
        return ansString;
    }
};

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums1[i] <= nums1[n - 1])
            {
                if (nums2[i] > nums2[n - 1])
                {
                    if (nums2[i] <= nums1[n - 1])
                    {
                        count++;
                    }
                    else
                    {
                        count = -1;
                        break;
                    }
                }
            }
            else
            {
            }
        }
    }
};

int con(string s)
{
    int val = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[s.size() - i - 1] == '1')
        {
            val += pow(2, i);
        }
    }
    return val;
}

string findDifferentBinaryString(vector<string> &nums)
{

    int n = nums[0].size();
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val += pow(2, i);
    }

    vector<int> helperVector(val + 1, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        helperVector[con(nums[i])] = 1;
    }
    for (int i = 0; i <= val; i++)
    {
        if (helperVector[i] == 0)
        {
            string ans = "";
            for (int j = 0; j < n; j++)
            {
                ans = ans + "0";
            }
            int j = n - 1;
            int temp = i;
            while (temp != 0)
            {
                ans[j--] = static_cast<char>(temp % 10);
                temp = temp / 10;
            }
            return ans;
        }
    }
    return "0";
}

class Solution
{
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int n = min(s1.size(), min(s2.size(), s3.size()));
        int k = -1;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i] && s1[i] == s3[i])
            {
                k = i;
            }
            else
            {
                break;
            }
        }

        return k == -1 ? (k) : ((s1.size() - k - 1) + (s2.size() - k - 1) + (s3.size() - k - 1));
    }
};
class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {
        int x = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            cout << (a >> (i)) << " " << (b >> (i)) << endl;
            cout << ((a >> (i)) | (b >> (i))) << endl;
            if (((a >> (i)) | (b >> (i))) % 2 == 0)
            {
                x = x << 1;
            }
            else
            {
                x = (x << 1) + 1;
            }
        }
        return (a ^ x) * (b ^ x);
    }
};

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (heights[i] < heights[j])
                {
                    um[i].push_back(j);
                }
            }
        }
        vector<int> ansVector;
        int m = queries.size();
        for (int i = 0; i < m; i++)
        {
            int a = min(queries[i][0], queries[i][1]);
            int b = max(queries[i][0], queries[i][1]);
            if (a == b)
            {
                ansVector.push_back(a);
            }
            else if (heights[a] < heights[b])
            {
                ansVector.push_back(b);
            }
            else
            {
                int k = um[b].size();
                bool flag = false;
                for (int j = 0; j < k; j++)
                {
                    if (heights[a] < heights[um[b][j]])
                    {
                        ansVector.push_back(um[b][j]);
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    ansVector.push_back(-1);
                }
            }
        }
        return ansVector;
    }
};

class Solution
{
private:
    int cal(int a)
    {
        string k = to_string(a);
        int n = k.size();
        string reverseString = "";
        for (int i = 0; i < n; i++)
        {
            reverseString = k[i] + reverseString;
        }
        return a + stoi(k);
    }

public:
    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = cal(nums[i]);
            if (um[temp] != 0)
            {
                count += um[temp];
            }
            um[temp]++;
        }
        return count;
    }
};

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int n = nums.size();
        map<int, vector<int>> ma;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            m = max(m, (int)nums[i].size());
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i].size() > j)
                {
                    ma[i + j].push_back(nums[i][j]);
                }
            }
        }
        vector<int> ansVector;
        for (auto i : ma)
        {
            for (int j = 0; j < i.second.size(); j++)
            {
                ansVector.push_back(i.second[j]);
            }
        }
        return ansVector;
    }
};

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                if (matrix[i][j] != 0)
                {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            sort(matrix[i].begin(), matrix[i].end());
            for (int j = 0; j < m; j++)
            {
                res = max(res, (j + 1) * matrix[i][j]);
            }
        }
        return res;
    }
};

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++)
        {
            // if(i % 2 == 0){
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != mat[i][(j + k) % m])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution
{
private:
    bool check(int v, int cons, int k)
    {
        if (v != cons)
        {
            return false;
        }
        else if ((v * cons) % k != 0)
        {
            return false;
        }
        return true;
    }

public:
    int beautifulSubstrings(string s, int k)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int v = 0;
            int cons = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                {
                    v++;
                }
                else
                {
                    cons++;
                }
                if (check(v, cons, k))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
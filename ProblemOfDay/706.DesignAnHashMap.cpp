#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class MyHashMap
{
public:
    vector<pair<int, int>> map;

    MyHashMap()
    {
        map = vector<pair<int, int>>();
    }

    void put(int key, int value)
    {
        bool flag = false;
        int n = map.size();
        for (int i = 0; i < n; i++)
        {
            if (map[i].first == key)
            {
                map[i].second = value;
            }
        }
        if (!flag)
        {
            map.push_back({key, value});
        }
    }

    int get(int key)
    {
        int n = map.size();
        for (int i = 0; i < n; i++)
        {
            if (map[i].first == key)
            {
                return map[i].second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int n = map.size();
        vector<pair<int, int>>::iterator it = map.begin();
        while (it != map.end())
        {
            pair<int, int> curPair = *it;
            if (curPair.first == key)
            {
                map.erase(it);
            }
        }
    }
};
int solution(vector<int> statues)
{
    int n = statues.size();
    int mi = statues[0];
    int ma = statues[0];
    for (int i = 0; i < n; i++)
    {
        mi = min(mi, statues[i]);
        ma = max(ma, statues[i]);
    }
    return (ma - mi) - n + 1;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "1,2000,5,1;1,2030,15,2;1,2000,10,1;2,2050,15,5;1,2067,8,6;2,2050,5,7";
    getline(cin, str);
    unordered_map<int, pair<double, int>> um;

    stringstream ss(str);
    string s;
    //
    int prev = INT_MIN;
    while (getline(ss, s, ';'))
    {
        int c = 0;
        string s1 = "";
        stringstream ss1(s);
        int k = 0;
        double value = 0;
        int quantity = 0;
        while (getline(ss1, s1, ','))
        {
            if (c == 0)
            {
                k = stoi(s1);
                c = 1;
                continue;
            }
            else if (c == 1)
            {
                value = stod(s1);
                c = 2;
                continue;
            }
            else if (c == 2)
            {
                quantity = stoi(s1);
                c = 3;
                continue;
            }
            else if (c == 3)
            {
                if (stoi(s1) > prev)
                {
                    prev = stoi(s1);
                    um[k].first = (um[k].first + quantity * value) / (um[k].second + quantity);
                    um[k].second = (um[k].second + quantity);
                    cout << k << ": " << um[k].first;
                }
                c = 0;
            }
        }
    }
}
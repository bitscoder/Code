#include <bits/stdc++.h>
#include <string>
using namespace std;
long long maximumTripletValue(vector<int> &nums)
{
    long long ans = 0;
    int n = nums.size();
    int a = nums[0];
    int b = nums[1];
    for (int i = 2; i < n; i++)
    {
        ans = ans > ((a - b) * nums[i]) ? ans : ((a - b) * nums[i]);
        if ((b - nums[i]) > (a - nums[i]))
        {
            if ((b - nums[i]) > (a - b))
            {
                a = b;
                b = nums[i];
            }
        }
        else
        {
            if ((a - nums[i]) > (a - b))
            {
                b = nums[i];
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //[1000000,1,1000000]

    vector<int> vec;
    //[1000000,1,1000000]
    vec.push_back(1000000);

    vec.push_back(1);
    vec.push_back(1000000);
    cout << (999999 * 1000000);
    cout << maximumTripletValue(vec);
}
string reverse(string s)
{
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        string temp(1, s[i]);
        ans += temp;
    }
    return ans;
}
string reverseWords(string s)
{
    string ansString = "";
    string currString = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            ansString += reverse(currString);
            currString = "";
        }
        else
        {
            string temp(1, s[i]);
            currString += temp;
        }
    }

    return ansString.substr(1, ansString.size()) + " " + currString;
}

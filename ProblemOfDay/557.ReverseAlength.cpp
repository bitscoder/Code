#include <bits/stdc++.h>
#include <string>
using namespace std;
long long maximumTripletValue(vector<int> &nums)
{
    vector<vector<int>> helperVector;
    helperVector.push_back({0});
    helperVector.push_back({1});
    helperVector.push_back({2,4,8,6});
    helperVector.push_back({3,6,9,7,1});
    helperVector.push_back({4,6});
    helperVector.push_back({5});
    helperVector.push_back({6});
    helperVector.push_back({7,9,3,1});
    helperVector.push_back({8,4,2,6});
    helperVector.push_back({9,1});
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
//Input: variables = [[39,3,1000,1000]]
vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<vector<int>> helperVector;
        helperVector.push_back({0});
        helperVector.push_back({1});
        helperVector.push_back({2,4,8,6});
        helperVector.push_back({3,6,9,7,1});
        helperVector.push_back({4,6});
        helperVector.push_back({5});
        helperVector.push_back({6});
        helperVector.push_back({7,9,3,1});
        helperVector.push_back({8,4,2,6});
        helperVector.push_back({9,1});
        vector<int> ansVector;
        int n = variables.size();
        for(int i = 0; i < n; i++){
            if(variables[i][3] > target){
                int temp1 = variables[i][1] % helperVector[variables[i][0]%10].size();
                int temp = helperVector[variables[i][0]%10][temp1 == 0 ? 0 : temp1 - 1];

                int a = variables[i][2] % helperVector[temp%variables[i][3]].size();
                int b = helperVector[temp%variables[i][3]][a == 0 ? 0 : a - 1];


                if(b == target){
                    ansVector.push_back(i);
                }
            }
        }
        return ansVector;
    }
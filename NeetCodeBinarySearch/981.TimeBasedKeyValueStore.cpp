#include<bits/stdc++.h>
using namespace std;

unordered_map <string,vector<pair<string, int>>> ans;
void set(string key, string value, int timestamp) {
    ans[key].push_back(make_pair(value, timestamp));
}
string binary(vector<pair<string, int>> ans1, int i, int j, int timestamp){
    if(i < j){
        int m = (i + j)/2;
        if(timestamp == ans1[m].second) return ans1[m].first;
        else if(timestamp > ans1[m].second)
            return binary(ans1, i, m, timestamp);
        else return binary(ans1, m+1, j, timestamp);
    }else return ans1[i].first;
}
string get(string key, int timestamp) {
    return binary(ans[key],0, ans[key].size(), timestamp);
}
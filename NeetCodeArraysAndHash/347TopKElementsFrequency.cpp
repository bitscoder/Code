#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
bool desc(pair<int, int> & a, pair<int, int> & b){
    return a.second > b.second;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> um;
    for(auto it: nums){
        um[it]++;
    }
    sort(um.begin(),um.end(),desc);
    vector<int> ans;
    for(auto it : um){
        ans.push_back(it.first);
        k--;
        if(k == 0) break;
    }
    return ans;
}

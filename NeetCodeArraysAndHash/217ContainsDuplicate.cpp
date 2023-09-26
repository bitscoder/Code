#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> map;
    for(auto it : nums){
        unordered_set<int> :: iterator ptr = map.find(it);
        if(ptr != map.end())
            return true;
        map.insert(it);
    }
    return true;
}
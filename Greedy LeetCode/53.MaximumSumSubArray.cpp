#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it: nums){
            if(s.find(it) == s.end()){
                s.insert(it);
            }
                
        }
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(check(j, i, s, nums))
                {
                    count = j+1;
                    break;
                }    
            }
        }
        return count;
    }
    bool check(int k, int l, unordered_set<int> n, vector<int> nums){
        unordered_set<int> s = n;
        
        for(int i = k; i <= l; i++){
            unordered_set<int>::iterator it = s.find(nums[i]);
            if( it != s.end()){
                s.erase(it);
            }
        }

        if(s.empty()) return true;
        else return false;
    }

int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it: nums){
                s.insert(it);
        }
        int n = nums.size();
        int count = 0;
        int dis = s.size();
        for(int i = dis - 1; i < n; i++){
            for(int j = i - dis; j >= 0; j--){
                if(check(j, i, s, nums))
                {
                    cout<< j<<i<< endl;
                    count += j+1;
                    break;
                }    
            }
        }
        return count;
    }
    bool check(int k, int l, unordered_set<int> n, vector<int> nums){
        unordered_set<int> s = n;
        
        for(int i = k; i <= l; i++){
            unordered_set<int>::iterator it = s.find(nums[i]);
            if( it != s.end()){
                s.erase(it);
            }
        }

        if(s.empty()) return true;
        else return false;
    }
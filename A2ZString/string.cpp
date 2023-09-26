#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

//205. Isomorphic Strings
bool isIsomorphic(string s, string t) {
    if(s.size() != t.size())return false;
    unordered_map<char, int> um_s;
    unordered_map<char, int> um_t;
    for(int i = 0; i < s.size(); i++){
        um_s[s[i]]++;
        um_t[t[i]]++;
    }
    for( auto pa : um_s){
        bool flag = false;
        for(auto ka : um_t){
            if(pa.second == ka.second){
                ka.second = -1;
                flag = true;
                break;
            }
        }
        if(!flag)return false;
    }
    return true;
}

int furthestDistanceFromOrigin(string moves) {
    int r = 0;
    int l = 0;
    int s = 0;

    for(char k : moves){
        if(k == 'R')
            r++;
        else if(k == 'L')
            l++;
        else s;
    }
    return max(r,l) - min(r,l)+ s;
}
long long minimumPossibleSum(int n, int k) {
    vector<int> ans;
    for(int i = 1; i <= k/2; i++){
        if(i <= n)
            ans.push_back(i);
    }
    int c = ans.size();
    if(c < n)
        for(int i = k; i < k + (n - c); i++){

            ans.push_back(i);
        }
    long long sum = 0;
    for(auto it: ans){
        sum += it;
    }
    return sum;
}
int minOperations(vector<int>& nums, int target) {
    int sum = 0;
    for(int i : nums){
        sum += i;
    }        
    
    if(sum < target)
        return -1;

    int temp = target;
    vector<int>targetVector (32, 0);
    int k = 0;
    while(temp > 0){
        targetVector[k++] = temp % 2;
        temp = temp/2;
    }
    vector<int>helpervector (31, 0);
    for(int k : nums){
        helpervector[log2(k)]++;
    }
    int ans = 0;
    for(int i = 0; i < 32; i++){
        if(targetVector[i] == 1){
            if(helpervector[i] > 0){
                helpervector[i]--;
            }else{
                for(int j = i + 1; j < 31; j++){
                    if(helpervector[j] > 0){
                        helpervector[j]--;
                        for(int d = j - 1; d >= i; d--){
                            ans++;
                            helpervector[d]++;
                        }
                        
                    }
                }
            }
            
        }
    }
    return ans;
}

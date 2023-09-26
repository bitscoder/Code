#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<int>>  vec(n, vector<int>(26, 0));
    for(int i = 0; i < n; i++){
        for(auto st : strs[i]){
            vec[i][(int)st - 97]++;
        }
    }
    vector<pair<vector<int>,vector<int>>> ansVector;
    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = 0; j< ansVector.size(); j++){
            if(check(ansVector[j].first, vec[i])){
                flag = true;
                vector<int> c = ansVector[j].second;
                c.push_back(i);
            }
        }
        if(!flag){
            vector<int>  dummy;
            dummy.push_back(i);
            ansVector.push_back(make_pair(vec[i], dummy));
        }
        
    }
    vector<vector<string>>  ansd;
    for(auto it : ansVector){
        vector<string> ans;
        for(auto it1 : it.second){
            ans.push_back(strs[it1]);
        }
        ansd.push_back(ans);
    }
    return ansd;
}
bool check(vector<int> a, vector<int> b){
    for(int j = 0; j < 26; j++){
        if(a[j] != b[j]){
            return false;
        }
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<long long>  vec(n, 0);
        for(int i = 0; i < n; i++){
            for(auto st : strs[i]){
                vec[i] += 2^((int)st - 97);
            }
        }
        vector<pair<long long,vector<int>>> ansVector;
        for(int i = 0; i < n; i++){
            bool flag = false;
            for(int j = 0; j < ansVector.size(); j++){
                if(ansVector[j].first == vec[i]){
                    //cout<< "ruturaj"<< endl;
                    flag = true;
                    vector<int> c = ansVector[j].second;
                    c.push_back(i);
                    ansVector[j].second = c;
                }
            }
            if(!flag){
                vector<int> dummy;
                dummy.push_back(i);
                ansVector.push_back(make_pair(vec[i], dummy));
            }
            
        }
        vector<vector<string>>  ansd;
        for(auto it : ansVector){
            vector<string> ans;
            for(auto it1 : it.second){
                ans.push_back(strs[it1]);
            }
            ansd.push_back(ans);
        }
        return ansd;
    }
    bool check(vector<int> a, vector<int> b){
        for(int j = 0; j < 26; j++){
            //cout<< a[j] << b[j];
            if(a[j] != b[j]){
                return false;
            }
        }
        //cout << endl;
        return true;
    }
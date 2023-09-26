#include<bits/stdc++.h>
using namespace std;
int checkUM(unordered_map<char, int > um){
    int sm = 0;
    for(auto u : um){
        sm = max(sm, u.second);
        //cout<< u.second<< endl;
    }
    return sm;
}
int characterReplacement(string s, int k) {
    int i = 0;
    int j = 0;

    int n = s.size();
    unordered_map<char, int > um;
    um[s[j]]++;
    //cout<< um[s[j]];
    //for(int i = 0;)
    int maxA = 0;
    
    while(j < n && i < n){
        //cout<< i << j <<"r"<<endl;
        //cout<< checkUM(um)<<endl;;
        if(k >= (j - i + 1) - checkUM(um)){
            //cout<< i<< j<<"j"<<endl;
            maxA = max((j - i + 1), maxA);
            
            j++;
            um[s[j]]++;
        }else{
            //cout<< i<< j<<"k"<<endl;
            um[s[i]]--;
            i++;
        }
    } 
    return maxA;
}

int main(){
    cout << characterReplacement("ABAB",2)<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int checkin( unordered_map<int, int> s1um,  unordered_map<int, int> s2um){
    int sums1 = 0;
    int sums2 = 0;

    for(int i = 0; i < 26; i++){
        sums2 += s2um[i];
        sums1 += s1um[i];
    }
    return sums1 - sums2;

}
bool de(unordered_map<int, int> s1um,  unordered_map<int, int> s2um){
    for(int i = 0; i < 26; i++){
        if(s2um[i] == s1um[i]){
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    if(n > m) return false;

    unordered_map<int, int> s1um;
    unordered_map<int, int> s2um;
    for(int i = 0; i < n; i++){
        s1um[s1[i] - 'a']++; 
        s2um[s2[i] - 'a']++;
    }
    int matches = 0;
    for(int i = 0; i < 26 ; i++){
        if(s1um[i] == s2um[i]) matches++;
    }
    
    if(matches == 26) return true;

    for(int i = n; i < m; i++){
        s2um[s2[i-n]]--;
        s2um[s2[i]]++;
        if(s2um[s2[i-n]] == s1um[s2[i-n]]) matches++;
        else matches--;

        if(s2um[s2[i]] == s1um[s2[i]]) matches++;
        else matches--;

        if(matches == 26)
            return true;
    }
    
   return false;
}
#include <bits/stdc++.h>
using namespace std;


string longestPalindrome(string s) {
    int n = s.size();
    string ans = "";
    for(int i = 0; i < n; i++){
        string cur = string(1,s[i]);
        for(int j = i + 1; j < n; j++){
            int k = i - (j - i);
            if(k < 0) break;
            if(s[j] == s[k]) cur = s[i] + cur + s[k];
            else break;
        }
        if(cur.size() > ans.size())
            ans = cur;
        cur = "";
        for(int j = i - 1; j >= 0; j--){
            int k = i + (i - j) - 1;
            if(k >= n) break;
            if(s[j] == s[k]) cur = s[i] + cur + s[k];
            else break;
        }
        if(cur.size() > ans.size())
            ans = cur;
    }
    return ans;
}
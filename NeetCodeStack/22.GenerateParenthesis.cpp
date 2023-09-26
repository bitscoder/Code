#include<bits/stdc++.h>
using namespace std;

void backTracking(vector<string>& ans, int open, int close, vector<char> ansStack, int n){
    if(open == n && close == n){
        string s;
        for(auto it : ansStack){
            s += (it);
        }
        ans.push_back(s);
        return;
    }
    if(open < n){
        ansStack.push_back('(');
        backTracking(ans, open + 1, close, ansStack, n);
        ansStack.pop_back();
    }
    if(close < open){
        ansStack.push_back(')');
        backTracking(ans, open, close + 1, ansStack, n);
        ansStack.pop_back();
    }   
    return;    
}
vector<string> generateParenthesis(int n) {
    vector<char> ansStack;
    vector<string> ans;
    backTracking(ans, 0, 0,ansStack, n);
    return ans;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> ansVector;
    vector<string> result;
    backtracking(s,0,result, ansVector);
    return ansVector;   
}
bool isPalidrome(string s, int i, int j){
    while(i < j){
        if(s[i++] != s[j--])return false;
    }
    return true;
}
void backtracking(string s, int start,vector<string>& result, vector<vector<string>>& ansVector ){
    if(start == s.size())ansVector.emplace_back(result);
    
    for(int i = start; i < s.size(); i++){
        if(isPalidrome(s, start, i)){
            result.push_back(s.substr(start, i - start + 1));
            backtracking(s, i+1, result, ansVector);
            result.pop_back();
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
}
string removeOuterParentheses(string s) {
    stack<char> ans;
    string a = "";

    ans.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(s[i] == ')'){
            if(ans.size() == 1){
                ans.pop();
            }
        }else{
            ans.push('(');
        }
    }        
}
//151. Reverse Words in a String
string reverseWords(string s) {
        
}
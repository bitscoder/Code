#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> ans;
    for(int i = 0 ; i < tokens.size(); i++ ){
        if (tokens[i] == "+"){
            int a = ans.top();
            ans.pop();
            int b = ans.top();
            ans.pop();
            ans.push(a + b);
        }else if (tokens[i] == "-"){
            int b = ans.top();
            ans.pop();
            int a = ans.top();
            ans.pop();
            ans.push(a - b);
        }else if (tokens[i] == "*"){
            int a = ans.top();
            ans.pop();
            int b = ans.top();
            ans.pop();
            ans.push(a * b);
        }else if (tokens[i] == "/"){
            int b = ans.top();
            ans.pop();
            int a = ans.top();
            ans.pop();
            ans.push(a / b);
        }else{
            ans.push(stoi(tokens[i]));
        }
    }   
    return ans.top();
}
#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
bool checkValidString(string s) {
    stack<char> sta;
    int s = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')'){
            char ele = sta.top();
            
            if(ele == '(')
                sta.pop();
            else return 0;

        }else sta.push(s[i]);
    }  
    if(sta.empty()) return true;
    else return false;      
}
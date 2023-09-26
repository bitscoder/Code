#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
bool isAnagram(string s, string t) {
    vector<int> sArray(123, 0);
    vector<int> tArray(123, 0);
    for(auto it : s){
        sArray[(int)it]++;
    }
    for(auto it : t){
        tArray[(int)it]++;
    }
    for(int i = 97; i< 123; i++){
        if(sArray[i] != tArray[i]) return false;
    }
    return true;
}
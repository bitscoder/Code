#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}
string largestOddNumber(string num) {
    for(int i = num.size() - 1; i >= 0; i--){
        if((num[i] - '0')%2 == 1){
            return num.substr(0, i + 1);
        }
    }    
    return "";
}

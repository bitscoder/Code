#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while(i <= j){
        int a = tolower(s[i]);
        int b = tolower(s[j]);

        if(a >= 97 && a <= 122)
        {
            if(b >= 97 && b <= 122)
            {
                if(b != a) return false;
            }
        }else {
            i++;
        }
        if(!(b >= 97 && b <= 122))
        {
            j--;
        }
    }  
         
}
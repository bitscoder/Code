#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int k = 1;
    for (int i = n-2;i>=0;i--){
        if(k <= nums[i])
            k = 1;
        else
            k++;
    }        
    if(k == 1)
        return true;
    else return false;
}
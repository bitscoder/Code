#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> right(n, 0);
    vector<int> left(n, 0);
    vector<int> ans;
    int product = 1;
    for(int i =0;i<n;i++){
        product *= nums[i];
        left[i] = product;
    }
    product = 1;
    for(int i = n-1; i >= 0; i--){
        product *= nums[i];
        right[i] = product;
    }
        
    for(int i = 0 ; i < n; i++){
        if(i - 1 < 0)
            ans.push_back(right[ i + 1]);
        else if(i + 1  ==  n)
            ans.push_back(left[ i - 1]);
        else
            ans.push_back(left[ i - 1] * right[ i + 1]);
    }
    return ans;
    
}
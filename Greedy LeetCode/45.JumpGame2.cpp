#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int jump(vector<int>& nums) {
    int k = 0;
    int n = nums.size();
    int maxIndex = n-1;
    int ans = 0;
    for(int i = n-1; i >=0; i--){
        for(int j = i; j >=0; j--){
            if(k <= nums[j])
                maxIndex = min(maxIndex, j);
            k++;
        }
        if(maxIndex != i){
            int a = i;
            i = maxIndex;
            k = 0;
            maxIndex = a;
            ans++;
        }
        else return 0;
    }
    return ans;
}
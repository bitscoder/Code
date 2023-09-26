#include <bits/stdc++.h>
using namespace std;
int main(){
    
}
int maxSubArray(vector<int>& nums) {
   int ans = INT_MIN;
   int curr = INT_MIN;
   for(int i : nums){
        if(curr < 0){
            curr = i;
        }else{
            curr += i;
        }
        ans = max(ans, curr);
   }
   return ans;  
}
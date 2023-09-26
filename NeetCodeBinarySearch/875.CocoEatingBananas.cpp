#include<bits/stdc++.h>
using namespace std;
int check(vector<int>& nums, int k){
    int h = 0;
    for(int i = 0; i < nums.size(); i++){
        h += nums[i]/k;
        h = nums[i]%k > 0 ? h + 1 : h;
    }
    return h;
}
int binary(vector<int>& nums, int h, int i, int j){
    if(i < j){
        int m = (j + i)/2;
        int k = check(nums, m);
        if( k < h){
            int d = binary(nums, h, i, m);
            if(d == -1){
                return k;
            }else return d;
        }else{
            return binary(nums, h, m+1, j);
        }
    }else return -1;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int minele = piles[0];
    int maxele = piles[0];
    for(auto it : piles){
        minele = min (minele, it);
        maxele = max (maxele, it);
    }
    binary(piles, h, minele, maxele);
}


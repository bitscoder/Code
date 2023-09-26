#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


    vector<int> ansVector(m + n);

    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n){
        if(nums1[i] <= nums2[j]){
            ansVector[k] = nums1[i];
            i++;
        }else{
            ansVector[k] = nums1[j];
            j++;
        }
        k++;
    }
    if(i == m){
        while(j<n){
            ansVector[k++] =  nums2[j];
            j++;
        }
    }else{
        while(i < m){
            ansVector[k++] =  nums1[i];
            i++;
        }
    }

    nums1 = ansVector;
        
}
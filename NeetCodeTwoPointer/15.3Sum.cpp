#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    
    //Sort the input array
    sort(nums.begin(),nums.end());

    //Initialize a set to store the unique triplets and an output vector to store the final result
    vector<vector<int>> ans;
    set<vector<int>> tempANs;
    //Iterate through the array with a variable i, starting from index 0.
    for(int i =0; i<n; i++){
        //Initialize two pointers, j and k, with j starting at i+1 and k starting at the end of the array.
        int j = i+1;
        int k = n-1;
        while(j < k){
            //In the while loop, check if the sum of nums[i], nums[j], and nums[k] is equal to 0. If it is, insert the triplet into the set and increment j and decrement k to move the pointers.
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                tempANs.insert({nums[i] ,nums[j] ,nums[k]});
            }
            //If the sum is less than 0, increment j. If the sum is greater than 0, decrement k.
            else if(sum < 0){
                j++;
            }else{
                k++;
            }
        }
    }
    //After the while loop, iterate through the set and add each triplet to the output vector.
    for(auto it : tempANs)
        ans.push_back(it);
    
    //Return the output vector
    return ans;

}
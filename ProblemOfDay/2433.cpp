#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int> findArray(vector<int> &pref)
{
    int n = pref.size();
    vector<int> ans(n);
    ans.push_back(pref[0]);
    for (int i = 1; i < n; i++)
    {
        ans.push_back(pref[i] ^ pref[i - 1]);
    }
    return ans;
}
int numUniqueEmails(vector<string> &emails)
{
}

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second > n / 2)
        {
            return i.first;
        }
    }
    return -1;
}
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    //vector<int> helperVector(n, -1);
    unordered_map<int, int> um;
    //um[nums2[n-1]] = -1;
    //int cur = nums2[n-1];

    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++){
            if(nums2[i] < nums2[j]){
                um[nums2[i]] = nums2[j];
                break;
            }else{
                um[nums2[i]] = -1;
            }
        }   
    }
    vector<int> ansVector;
    for (int i = 0; i < nums1.size(); i++)
    {
        ansVector.push_back(um[nums1[i]]);
    }
    return ansVector;
}
//724
int pivotIndex(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        sum += nums[i];
    }
    int leftSum = 0;
    for(int i = 0; i < n; i++){
        sum = sum - nums[i];
        if(leftSum == sum)return i;
        leftSum =  leftSum + nums[i];
    }
    return -1;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_map<int, int> um;
    for(int i = 0; i < nums.size(); i++){
        um[nums[i]] = 1;
    }        
    vector<int> ansVector;

    for(int i = 1; i <= nums.size(); i++){
        if(um[i] ==  0){
            ansVector.push_back(i);
        }
    }
    return ansVector;
}


int maxNumberOfBalloons(string text) {
    int n = text.size();
    unordered_map<int, int> um;
    for(int i = 0; i < n; i++){
        um[text[i] - 'a']++;
    }    
    int cur = INT_MAX;
    cur = min(cur, um['b'-'a']);
    cur = min(cur, um['a'-'a']);
    cur = min(cur, um['l'-'a']/2);
    cur = min(cur, um['o'-'a']/2);
    cur = min(cur, um['n'-'a']);
    return cur;
}
int arraySign(vector<int>& nums) {
    int negative = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == 0)return 0;
        if(nums[i] < 0 )negative++;
    }
    if(negative%2 == 1)return -1;
    else return 1;
}

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> um;
    for(int i = 0; i< nums2.size(); i++){
        um[nums2[i]] = 1;
    }
    vector<vector<int>> ansVector;
    vector<int> ansVector1;
    for(int i = 0; i< nums1.size(); i++){
        if(um[nums1[i]] == 0){
            ansVector1.push_back(nums1[i]);
        }
    }
    ansVector.push_back(ansVector1);
    unordered_map<int, int> um1;
    for(int i = 0; i< nums1.size(); i++){
        um1[nums1[i]] = 1;
    }
    vector<int> ansVector2;
    for(int i = 0; i< nums2.size(); i++){
        if(um[nums2[i]] == 0){
            ansVector2.push_back(nums2[i]);
        }
    }
    ansVector.push_back(ansVector2);
    return ansVector;
}
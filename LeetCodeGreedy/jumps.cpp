#include<bits/stdc++.h>
using namespace std;

int MaxJump(int currentPos, vector<int>& nums, int d){
    if(currentPos == nums.size() - 1)
        return 0;
    int currentMax = -1;
    for(int i = currentPos + 1 ; i < nums.size(); i++){
        if((nums[i] - nums[currentPos] <= d ) && -1 * d <= nums[i] - nums[currentPos]){
            int current = MaxJump(i, nums,d);
            if(current > currentMax)
                currentMax = current;
        }
    }
    return currentMax == -1 ? currentMax : currentMax + 1;
}
int maximumJumps(vector<int>& nums, int target) {
        
        vector<int> tapVector(nums.size(), -1);
        tapVector[0] = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0;j<i; j++){
                if(abs(nums[i] - nums[j])<= target && tapVector[i]!= -1){
                    tapVector[i] = max(tapVector[i],tapVector[j]+1);
                }
            }
        }

        return tapVector[nums.size() - 1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    int target = 2;

    int jumps = 0;
    int local = 0;
    int k = 0;
    for(int i = 0; i < nums.size();){
        for( int j = i + 1; j < nums.size(); j++){
            if((nums[j] - nums[i] <= target ) && -1 * target <= nums[j] - nums[i] ){
                jumps ++;
                local = j;
                //cout<< i << "ruturaj"<< endl;
                break;
            }
        }
        if(i == local)
            break;
        else
            i = local;
        
    }

    if(local == nums.size() - 1)
        cout <<  jumps;
    else
        cout <<  -1;
}
int maximumJumps(vector<int>& nums, int target) {
        int jumps = 0;
       int local = 0;
       for(int i = 0; i < nums.size();){
            for( int j = i + 1; j < nums.size(); j++){
                if((nums[j] - nums[i] <= target ) && -1 * target <= nums[j] - nums[i] ){
                    jumps ++;
                    local = j;
                    //cout<< i << "ruturaj"<< endl;
                    break;
                    
                }
            }
            if(i == local)
                i++;
            else
                i = local;
       }

       if(local == nums.size() - 1)
            cout <<  jumps;
        else
            cout <<  -1;
    }
#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftVector;
    vector<int> rightVector;
    int minTemp = 0;
    for(int i = 0; i<n; i++){
        leftVector[i] = minTemp;
        minTemp = max(minTemp, height[i]);
    }
    minTemp = 0;
    for(int i = n-1; i>=0; i--){
        rightVector[i] = minTemp;
        minTemp = max(minTemp, height[i]);
    }
    int sum = 0;
    for(int i = 0; i< n; i++){
        sum = min(leftVector[i],rightVector[i]) - height[i];
    }
    return sum;

}
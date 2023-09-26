#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int globalMax = 0;
    while(i < j){
        globalMax = max(globalMax,min(height[i],height[j]) * (j-i));
        if(height[i] <= height[j]) i++;
        else j--;
    }   
    return globalMax;     

}
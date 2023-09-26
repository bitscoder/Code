#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

int rec(int curr, vector<int>& arr, int difference, vector<int>& tapArray){
    if(tapArray[curr] != 0)
        return tapArray[curr];
    int index = 0;
    int val = difference + arr[curr];
    for(int i = curr +1; i < arr.size(); i++ ){
        if(arr[i] == val){
            index = i;
            break;
        }
    }
    tapArray[curr] = index == 0 ? 1 : 1 + rec( index, arr, difference, tapArray);
    return tapArray[curr];
}
int longestSubsequence(vector<int>& arr, int difference) {
    int m = arr.size();
    vector<int> ansVector(m, 1);
    for(int i = 1; i< m; i++){
        for(int j = i - 1; j >= 0; j--){
            if(arr[i] - arr[j] == difference){
                ansVector[i] = ansVector[j] + 1;
                break;
            }
        }
    }
    int ansMax = 0;
    for( auto it : ansVector){
        ansMax = max(ansMax, it);
    }
    return ansMax;
    
    vector<int> tapArray (m, 0);
    for ( int i = 0; i< m ; i++){
        if(tapArray[i] == 0){
            rec(i, arr, difference, tapArray);
        }
    }

    int ansMax = 0;
    for( auto it : tapArray){
        ansMax = max(ansMax, it);
    }
    return ansMax;
}
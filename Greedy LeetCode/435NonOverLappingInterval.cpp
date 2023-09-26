#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
bool sortbysec(const vector<int> &a, const vector<int> &b)
{
    return (a[1] < b[1]);
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), sortbysec);
    pair<int, int> currPair;
    int count = 1;
    currPair = make_pair(intervals[0][0], intervals[0][1]);

    for(int i = 1; i < intervals.size(); i++){
        if(currPair.second <= intervals[i][0]){
            count++;
            currPair = make_pair(intervals[i][0], intervals[i][1]);
        }
    }
    return intervals.size() - count;
}
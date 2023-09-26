#include<bits/stdc++.h>
using namespace std;



int largestRectangleArea(vector<int>& heights) {
    int ansArea = 0;
    stack<pair<int, int>> helperStack;
    helperStack.push(make_pair(0, heights[0]));
    int n = heights.size();
    for(int i = 1; i < n; i++){
        int j = i;
        while(!helperStack.empty() && helperStack.top().second > heights[i] ){
            ansArea = max(ansArea, (i - helperStack.top().first) * helperStack.top().second );
            j = helperStack.top().first;
            helperStack.pop();
        }
        helperStack.push({j, heights[i]});
    }     
    while(!helperStack.empty()){
        ansArea = max(ansArea, (n - helperStack.top().first) * helperStack.top().second);
        helperStack.pop();
    }
    return ansArea;

}
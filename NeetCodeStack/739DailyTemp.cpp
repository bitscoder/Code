#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

    vector<int> ans(temperatures.size(), 0);
    stack<pair<int,int> > ansStack;
    ansStack.push(make_pair(temperatures[0], 0));
    for(int i = 1; i < temperatures.size(); i++){
        while(ansStack.top().first < temperatures[i]){
            ans[ansStack.top().second] = i - ansStack.top().second;
            ansStack.pop();
        }
        ansStack.push(make_pair(temperatures[i], i));
    }
    while (!ansStack.empty())
    {
        ans[ansStack.top().second] = 0;
        ansStack.pop();
    }
    return ans;        
}
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    dailyTemperatures(a);
}
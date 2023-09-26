#include<bits/stdc++.h>
using namespace std;
static bool ch(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>>  dataVector;
    for(int i = 0; i< position.size(); i++){
        dataVector.push_back(make_pair(position[i], speed[i]));
    }
    sort(dataVector.begin(), dataVector.end(), ch);

    stack<pair<int, int>> ansStack;

    ansStack.push(dataVector[0]);

    for(int i = 1; i < position.size(); i++){
        while ((target - ansStack.top().first)/ansStack.top().second < (target - dataVector[i].first)/dataVector[i].second)
        {
            ansStack.pop();
        }
        ansStack.push(dataVector[i]);
        
    }
    return ansStack.size();

}
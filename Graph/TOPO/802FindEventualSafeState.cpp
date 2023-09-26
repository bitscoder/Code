#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<vector<int>> antiGragh;
    for(int i = 0; i < graph.size(); i++){
        for(auto it : graph[i]){
            antiGragh[it].push_back(i);
        }
    }

    vector<int> indegree(graph.size(), 0);

    for(int i = 0; i < antiGragh.size(); i++){
        for(auto it : antiGragh[i]){
            indegree[it]++;
        }
    }

    queue<int>  dfsQueue;

    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0)
            dfsQueue.push(i);
    }
    vector<int> ansVector;

    while(!dfsQueue.empty()){
        int node = dfsQueue.front();
        dfsQueue.pop();
        ansVector.push_back(node);
        for(auto it : antiGragh[node]){
            indegree[it] --;
            if(indegree[it] == 0) dfsQueue.push(it);
        }
    }

}
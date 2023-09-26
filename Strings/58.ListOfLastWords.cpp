#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];
    for(int i =0;i< m;i++){
        int u,v;
        cin>> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    vector<int> adjList[n+1];
    for(int i = 0; i< m ; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }
    int* keepTapArray = new int[n+1];
    keepTapArray[1] = 1;
    queue<int> bfs;
    bfs.push(1);
    vector<int> answerVector;

    while(!bfs.empty()){
        int nodeValue = bfs.front();
        bfs.pop();
        answerVector.push_back(nodeValue);
        for(auto it : adjList[nodeValue]){
            if(!keepTapArray[it]){
                keepTapArray[it] = 1;
                bfs.push(it);
            }
        }
    }
    keepTapArray[1] = 1;
    answerVector.push_back(1);
    dfs(keepTapArray,adjList,1,answerVector);
}
void dfs(int* keepTapArray, vector<int>  adjList[], int currentNode, vector<int> answerVector){
    for(auto it : adjList[currentNode]){
        if(!keepTapArray[it]){
            answerVector.push_back(it);
            dfs(keepTapArray, adjList, currentNode, answerVector);
        }
        
    }

}

int lengthOfLastWord(string s) {
        string ansString = "";
        //
}
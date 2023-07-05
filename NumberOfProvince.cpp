#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int findCircleNum(vector<vector<int>>& isConnected) {
        int answercount = 0; 
        int* arr = new int[isConnected.size()];

        for( int i = 0;i < isConnected.size(); i++){
            if(arr[i]!= 1){
                answercount++;
                queue<int> bfs;
                bfs.push(i);
                while(!bfs.empty()){
                    int node = bfs.front();
                    bfs.pop();
                    arr[node] = 1;
                    for(int j = 0; j < isConnected.size(); j++){
                        if(isConnected[node][j] == 1 && arr[j]!=1){
                            bfs.push(j);
                        }
                    }
                }

            }
        }
        return answercount;
    }
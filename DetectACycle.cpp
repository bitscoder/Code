#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> adjList[10];
    // BFS
    queue<pair<int, int>> bfsQueue;

    // tap array
    int * tapArray = new int[10];
    
    vector<int> ansVector;
    for(int i = 0; i < 10; i++){
        if(tapArray[i] != 1){
            tapArray[i] = 1;
            bfsQueue.push({i, -1});
            ansVector.push_back(i);
            while(!bfsQueue.empty()){
                int nodeValue = bfsQueue.front().first();
                int parentNode = bfsQueue.front().second();
                bfsQueue.pop();
                for(auto it : adjList[nodeValue]){
                    if(tapArray[it] != 1){
                        tapArray[it] = 1;
                        bfsQueue.push({it,nodeValue});
                        ansVector.push_back(it);
                    }else(it != parentNode){
                        for(auto it1: ansVector){
                            cout << it << endl;
                        }
                        return true;
                    }
                }
            }
        }
        ansVector = new vector<int>();
    }
    //for(int i = 1; )
    

}
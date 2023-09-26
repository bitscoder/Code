#include<bits/stdc++.h>
using namespace std;
bool pacificdfs(vector<int> adjList[], vector<int>& mem, int k, int m, vector<int>& pacdfs){
    if(k/m == 0 || k % m == 0)return true;
    
    for(int i = 0; i < adjList[k].size(); i++){
        if(mem[adjList[k][i]] == 0){
            mem[adjList[k][i]] = 1;
            if(pacdfs[adjList[k][i]] == -1){
                bool flag =  pacificdfs(adjList, mem, adjList[k][i], m,pacdfs);
                if(flag){
                    pacdfs[adjList[k][i]] = 1;
                    return true;
                }else{
                    pacdfs[adjList[k][i]] = 0;
                }
            }else if(pacdfs[adjList[k][i]] == 1){
                return true;
            }
        }
    }
    return false;
}
bool atlanticdfs(vector<int> adjList[], vector<int>& mem, int k, int m, int n, vector<int>& atldfs){
    if(k/m == n - 1 || k % m == m - 1)return true;
    
    for(int i = 0; i < adjList[k].size(); i++){
        if(mem[adjList[k][i]] == 0){
            mem[adjList[k][i]] = 1;
            if(atldfs[adjList[k][i]] == -1){
                bool flag =  atlanticdfs(adjList, mem, adjList[k][i], m, n,atldfs);
                if(flag){
                    atldfs[adjList[k][i]] = 1;
                    return true;
                }else{
                    atldfs[adjList[k][i]] = 0;
                }
            }else if(atldfs[adjList[k][i]] == 1){
                return true;
            }
        }
    }
    return false;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();


    // adjList 
    vector<int> adjList[m*n];
    int dim[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int nrow = i + dim[k][0];
                int ncol = j + dim[k][1];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    if(grid[i][j] > grid[nrow][ncol]){
                        adjList[i * m + j].push_back(nrow * m + ncol);
                    }
                }
            }
        }
    }
    vector<int> pacdfs(m*n, -1);
    vector<int> atldfs(m*n, -1);
    vector<vector<int>> ans;
    
    for(int i = 0; i < m * n; i++){
        vector<int> mem(m * n, 0);
        vector<int> mem1(m * n, 0);
        mem[i] = 1;mem1[i] = 1;
        bool flag1;
        if(pacdfs[i] == -1){
            flag1 = pacificdfs(adjList, mem, i, m,pacdfs);
            pacdfs[i] = flag1 == true ? 1 : 0;
        }else{
            flag1 = pacdfs[i] == 1 ? true: false;
        }
        
        bool flag2;
        if(atldfs[i] == -1){
            flag2 = atlanticdfs(adjList, mem1, i , m, n, atldfs);
            atldfs[i] = flag2 == true ? 1 : 0;
        }else{
            flag2 = atldfs[i] == 1 ? true: false;
        }
        if(flag1 && flag2){
            vector<int> a;
            a.push_back(i/m);
            a.push_back(i%m);
            ans.push_back(a);
        }
        
    } 
    return ans;
}
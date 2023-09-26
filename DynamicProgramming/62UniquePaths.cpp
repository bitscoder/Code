#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int uniquePaths(int m, int n) {

    int arr[m][n];

    for(int i = 0; i < n; i++)
        arr[m -1][i] = 1;
    
    for(int i = 0; i < m; i++)
        arr[i][n - 1] = 1;
    
    arr[m-1][n-1] = 0;

    for(int i = m - 1; i >= 0; i++){
        for(int j = n - 1; j >= 0; j++){
            arr[i][j] = arr[i+1][j] + arr[i][j+1];
        }
    }

    return arr[0][0];
}
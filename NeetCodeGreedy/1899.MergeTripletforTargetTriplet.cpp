#include<bits/stdc++.h>
using namespace std;
/*Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. triplets = [[2,5,3],[1,8,4],[2,7,5]]
The target triplet [2,7,5] is now an element of triplets.*/

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<vector<int>> helperVector[3];
    for(vector<int> t : triplets)
    {
        if(t[0] == target[0]){
            helperVector[0].push_back(t);
        }
        if(t[1] == target[1]){
            helperVector[1].push_back(t);
        }
        if(t[2] == target[2]){
            helperVector[2].push_back(t);
        }
    }
    int a = helperVector[0].size();
    int b = helperVector[1].size();
    int c = helperVector[2].size();
    if(a == 0 || b == 0 || c==0)return false;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            for(int k = 0; k < c; k++){
                if((helperVector[0][i][0] >= helperVector[1][j][0] && helperVector[0][i][0] >= helperVector[2][k][0]) &&
                    (helperVector[1][j][1] >= helperVector[0][i][1] && helperVector[1][j][1] >= helperVector[2][k][1]) &&
                    (helperVector[2][k][2] >= helperVector[1][j][2] && helperVector[2][k][2] >= helperVector[0][i][2])){
                        return true;
                    }
            }
        }
    }
    return false;
}
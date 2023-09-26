#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<int> temp(1,1);
    ans.push_back(temp);
    
    for(int i = 2; i <= numRows; i++){
        vector<int> temp1(i,1);
        vector<int> temp2 = ans[ans.size()-1];
        for(int j = 0; j <  i; j++){
            temp1[j] = (j - 1 < 0 ? 0 : temp2[j-1]) + (j >= temp2.size() ? 0 : temp2[j]);
        }
        ans.push_back(temp1);
    }
    return ans;
}
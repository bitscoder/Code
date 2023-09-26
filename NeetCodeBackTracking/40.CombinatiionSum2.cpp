#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
    vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, target, 0, current, result);
    return result;
}
void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }else if(target < 0 || candidates.size() <= start) return;

    current.push_back(candidates[start]);
    backtrack(candidates, target - candidates[start], start+1, current, result);
    current.pop_back(); // Backtrack by removing the last element

    while(start+1 < candidates.size() && candidates[start] == candidates[start+1]){
        start++;
    }
    backtrack(candidates, target, start+1, current, result);
    
}
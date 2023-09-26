#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    return backtracking(candidates, target, candidates.size());
}
vector<vector<int>> backtracking(vector<int>& candidates, int target, int n){
    if(target < 0){
        return vector<vector<int>>();
    }else if(target == 0){
        vector<vector<int>> ans;
        vector<int> k;
        ans.emplace_back(k);
        return ans;
    }
    vector<vector<int>> ans;
    for(int i : candidates){
        vector<vector<int>> ans1 = backtracking(candidates, target - i, n);
        for(vector<int> d : ans1){
            d.emplace_back(i);
            ans.emplace_back(d);
        }
    }
    return ans;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
    }
    for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i, current, result);
        current.pop_back(); // Backtrack by removing the last element
    }
}
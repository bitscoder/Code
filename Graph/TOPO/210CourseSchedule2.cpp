#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    cout<<minimumIndex(nums)<< endl;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> graphVector [numCourses];
    for(int j = 0; j< prerequisites.size(); j++){
        for(int i = 0; i < prerequisites[j].size(); i++){
            if (i+1 < prerequisites[j].size())
                graphVector[prerequisites[j][i+1]].push_back(prerequisites[j][i+1]);
        }
    }

    // count the indegree
    vector<int> indegree(numCourses, 0);

    for(int i = 0; i < numCourses; i++){
        for( int j = 0; j < graphVector[i].size(); j++){
            indegree[graphVector[i][j]]++;
        }
    }
    //kanhs algo

    queue<int> bfsQueue;

    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0)
            bfsQueue.push(i);
    }
    vector<int> ansVector;
    while (!bfsQueue.empty())
    {
        int node = bfsQueue.front();
        ansVector.push_back(node);
        bfsQueue.pop();

        for(auto it: graphVector[node]){
            indegree[it]--;
            if(indegree[it] == 0) bfsQueue.push(it);
        }
    }
    
    return ansVector;
}

int minimumIndex(vector<int>& nums) {
    vector<int>  numduplicate;
    int n = nums.size();
    numduplicate = nums;
    sort(nums.begin(),nums.end());

    int number = nums[0];
    int mode = number;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<n; i++)
    {
        if (nums[i] == number) 
            ++count;
        
        else
        { 
                if (count > countMode) 
                {
                    countMode = count; 
                    mode = number;
                }
            count = 1; 
            number = nums[i];
        }
    }  
    if(n == 1)
        return -1;
    int valLeft = 0;
    for(int i = 0; i < n ; i++){
        if(nums[i] == mode)
            valLeft ++;
        if(valLeft * 2 > i + 1 && (countMode - valLeft) * 2 > (n - i -1) )return i;
    }
    return -1;

}
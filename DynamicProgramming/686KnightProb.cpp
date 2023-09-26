#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
int dir[8][8] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
double knightProbability(int n, int k, int row, int column) {
    queue<pair<pair<pair<int,int>, int>,double>> bfsQueue;

    int j = 1;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    bfsQueue.push(make_pair(make_pair(make_pair(row,column),j),1));
    

    while(!bfsQueue.empty() && j <= k){
        while (!bfsQueue.empty() && bfsQueue.front().first.second == j){
            int r = bfsQueue.front().first.first.first;
            int c = bfsQueue.front().first.first.second;
            double prob =  bfsQueue.front().second;
            bfsQueue.pop();
            vec[r][c] = prob;

            for(int i=0; i<8; i++){
                int rCurr = r + dir[i][0];
                int cCurr = c + dir[i][1];
                if(Check(rCurr, cCurr, n) && vec[rCurr][cCurr] == 0){

                    bfsQueue.push(make_pair(make_pair(make_pair(rCurr, cCurr), j + 1), prob/8));
                }
                    
            }
            cout<< j << endl;
        }
        j++;
    }
    double ans = 0;
    while (!bfsQueue.empty() && bfsQueue.front().first.second == k+1){
        ans += bfsQueue.front().second;
        bfsQueue.pop();
    }
    return ans;
}
bool Check(int r, int c, int n){
    if(r<0 || r>=n || c<0 || c>=n)
            return false;
    return true;
}
vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    string s = "scott>=tiger>=mushroom";
    string delimiter = ">=";

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    std::cout << s << std::endl;
    vector<string> ans;
    string token;
    for(auto it :words){
        size_t pos = 0;
        string token;  
        while ((pos = s.find(separator)) != std::string::npos) {
            token = it.substr(0, pos);
            ans.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        ans.push_back(it);
    }

    return ans;
}

long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    long long dp[n];
    for(int i = 1; i<n; i++)
        dp[i] = 0;
    
    dp[0] = nums[0];
    for(int i = 1; i<n; i++){
        if(nums[i] < nums[i-1] )
            dp[i] = dp[i-1];
        if(nums[i] >= nums[i-1] && nums[i] + nums[i - 1] < nums[i] + dp[i-1])
            dp[i] = nums[i] +  dp[i-1];
        if(nums[i] >= nums[i-1] && nums[i] + nums[i - 1]> nums[i] +  dp[i-1]){
            long long sum = nums[i];
        }
    }
    return nums[n-1];
}
long long maxArrayValue(vector<int>& nums) {
    int n = nums.size();
    long long dp[n];
    for(int i = 1; i<n; i++)
        dp[i] = 0;
    
    dp[0] = nums[0];
    for(int i = 1; i<n; i++){
        if(nums[i] < nums[i-1] )
            dp[i] = dp[i-1];
        if(nums[i] >= nums[i-1] ){
            long long sum  = nums[i];

            for(int j = i - 1; j>= 0; j--){
                if(sum >= nums[j]){
                    dp[i] = max(dp[i], sum + dp[j] );
                    sum += nums[j];
                }else
                    break;
                    
            }

            dp[i] = nums[i] +  dp[i-1];
        }
            
        
    }
    return dp[n-1];
}
#include<bits/stdc++.h>
using namespace std;
int main()
{}
/*Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.*/
bool check(vector<int>& gas, vector<int>& cost, int k, int n){
    int tank = 0;
    for(int i = k; i <= k + n; i++){
        tank = tank + gas[i] - cost[i];
        if(tank < 0){
            return false;
        }
    }
    return true;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    vector<int> dp(n, 0);
    int sum = 0;
    for(int i = 0; i < n; i++){
        dp[i] = gas[i]- cost[i];
        sum += dp[i];
    }
    if(sum < 0){
        return -1;
    }

    int index = n - 1;
    int curr = 0;
    sum = INT_MIN;
    for(int i = n - 1; i >= 0; i--){
        curr += dp[i];
        if(sum < curr){
            sum = curr;
            index = i;
        }
    }
    return index;
}
#include<bits/stdc++.h>
using namespace std;

/*Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]*/

bool isNStraightHand(vector<int>& hand, int groupSize) {

    sort(hand.begin(), hand.end());
    
    int n = hand.size();
    if(n % groupSize > 0)return false;
    int k = n/groupSize;
    vector<int> dp(n, 0);
    for(int i = 0; i < k ;i++){
        int k = -1;
        int count = 0;
        for(int j = 0; j < n; j++){
            if(k == -1 && dp[j] == 0){
                dp[j] = i+1;
                k = hand[j];
                count++;
            }
            else if(dp[j] == 0 && !(hand[j] == k || hand[j] == k + 1)){
                
                return false;

            }
            else if(dp[j] == 0 && hand[j] == k+1){
                k = k + 1;
                dp[j] = i+1;
                count++;
            }
            if(count == groupSize) break;
        }
    }
    return true;
}
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(6);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(7);
    a.push_back(8);
    cout << isNStraightHand(a, 3);
}

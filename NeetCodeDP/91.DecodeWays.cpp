#include <bits/stdc++.h>
using namespace std;
/*Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).*/
int numDecodings(string s) {
    int n = s.size();
    vector<int> dp (n, 0);
    dp[0] = s[0]-'0' == 0 ? 0 : 1 ;
    for(int i = 1; i < n; i++){
        if((s[i - 1]-'0' == 2 && s[i] - '0' > 0 && s[i] - '0' <= 6)|| (s[i - 1]-'0' == 1 && s[i] - '0' > 0 ) ){
            dp[i] = dp[i-1] + 1;
        }
        else dp[i] = dp[i - 1];
    }
    return dp[n - 1];
}
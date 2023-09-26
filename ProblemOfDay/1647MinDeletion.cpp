#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}
int minDeletions(string s) {
    vector<int> tapVec(26, 0);
    for(auto i : s){
        tapVec[i - 'a']++;
    }  
    sort(tapVec.begin(), tapVec.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < 26; true){
        if(tapVec[i] == 0)break;
        int k = 0;
        for(int j = i + 1; j < 26; j++){
            if(tapVec[i] == tapVec[j]){
                ans = ans + (++k);
                if(tapVec[j] < k){
                    tapVec[j] = 0;
                    for(int d = j + 1; d < 26; d++)
                    tapVec[d] = 0;
                }
                tapVec[j] = tapVec[j] - k;
            }else break;
        }
        i = i + k;
        if(k == 0) i++;
    }
    return  ans;
}

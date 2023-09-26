#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

}

int longestPalindrome(string s) {
    long long n = s.size();
    vector<int> tapVector(n, 0);
    long long answer;
    for(int i=0;i<n;i++){
        for(int j = 0; j < n; j++){
            if(i!=j && s[i] == s[j] && tapVector[i] + tapVector[j]== 0){
                answer += 2;
                tapVector[i] = tapVector[j] = 1;
            }
        }
    }
    if(answer != n)
        answer++;
    return answer;
}
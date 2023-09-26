#include <bits/stdc++.h>
using namespace std;
bool check(pair<int,int>& a, pair<int, int>& b){
    return a.first < b.first;
}
vector<int> partitionLabels(string s) {
    vector<pair<int, int> > um(26, make_pair(-1,-1));
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(um[s[i] - 'a'].first == -1){
            um[s[i] - 'a'] = make_pair(i,i);
        }else{
            um[s[i] - 'a'].second = i;
        }
    }
    sort(um.begin(), um.end(), check);
    vector<int> ans;
    pair<int, int> curr= make_pair(-1,-1);
    for(auto interval : um){
        if(interval.first != -1){
            //cout << interval.first << " " << interval.second << endl;
            if(curr.first == -1)
                curr = interval;
            else if(curr.second < interval.first){
                ans.push_back(curr.second -  curr.first + 1);
                curr = interval;
            }
            else if(curr.second < interval.second){
                curr.second =  interval.second;
            }
        }
    }
    ans.push_back(curr.second -  curr.first + 1);
    return ans;
}

int countSymmetricIntegers(int low, int high) {
    int ans = 0; 
    for(int i = low; i <= high; i++){
        string s = to_string(i);
        int n = s.size();
        if(n%2 == 1)continue;
        int leftSum = 0;
        int rightSum = 0;
        for(int j = 0; j < n; j++){
            if(j < n/2){
                leftSum += s[j] - '0';
            }else{
                rightSum += s[j] - '0';
            }
        }
        if(leftSum == rightSum)ans++;
    }   
    return ans;
}
int minOperations(string num, char front, char back){
    bool flag = false;
    int n = num.size();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(num[i] == back && flag == false){
            flag = true;

        }else if(num[i] == front && flag){
            break;
        }else ans++;
            
    }
    return ans;
}
int minimumOperations(string num) {
    if(num.size() <= 2) return num.size();
    return min(minOperations(num, '2', '5'),min(minOperations(num, '5', '0'),min(minOperations(num, '7', '5'),minOperations(num, '0', '0'))));
}
int main()
{
    vector<int>  ans =  partitionLabels("caedbdedda");
    for(int i : ans){
        cout << i<< endl;
    }
    cout<< countSymmetricIntegers(1, 100);
}



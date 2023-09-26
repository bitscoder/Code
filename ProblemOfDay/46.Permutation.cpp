#include<bits/stdc++.h>
using namespace std;
void permute(vector<int>& nums) {
    int fact = 1;
    int n = nums.size();
    
    for(int i = 1; i <= n; i++)
        fact *= i;
    vector<int> s[fact];
    
    for(int l = n ; l > 0; l--){
        
        fact = fact/l;
        //for(int d = n-1)
        int j = n-l;
        for(int i = 0; i < l; i++){
            int ele = nums[(j++)%n];
            for(int k = 0; k < fact; k++){
                s[(fact)*i + k].push_back(ele);
            }
        }
    }
    for(auto it: s){
        for(auto it1: it){
            cout << it1;
        }
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    permute(vec);
}

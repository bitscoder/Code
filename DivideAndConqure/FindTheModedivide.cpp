#include<bits/stdc++.h>
using namespace std;
pair<int, int> divide(vector<int>& ansVector, int i, int j){
    if(i == j)
        return make_pair(ansVector[i], 1);
    //if(i < 0)
    int m = j-i/2;
    pair<int, int> left = divide(ansVector, i, m);
    pair<int, int> right = divide(ansVector, m+1, j);
    if(left.first == right.first)
        return make_pair(left.first, left.second + right.second);
    else{
        pair<int,int> ansPair = left.second > right.second ? left : right;
        return ansPair;
    }
        
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    vector<int> ansVector;

    ansVector.push_back(1);
    ansVector.push_back(1);
    ansVector.push_back(1);
    ansVector.push_back(1);
    ansVector.push_back(1);
    ansVector.push_back(1);
    ansVector.push_back(1);
    ansVector.push_back(1);
    cout << divide(ansVector, 0, ansVector.size() - 1).first<< endl;
}


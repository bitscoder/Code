#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    while(i < j){
        
        if(numbers[i] + numbers[j] == target)
        {   
            vector<int> vec;
            vec.push_back(i+1);
            vec.push_back(j+1);
            return vec;                
        }
        else if(numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else if(numbers[i] + numbers[j] > target)
        {
            j--;
        }
    }
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(-1);
    return vec; 
}
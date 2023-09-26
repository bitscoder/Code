#include<bits/stdc++.h>
using namespace std;
int minimumIndex(vector<int>& nums) {
    vector<int>  numduplicate;
    int n = nums.size();
    numduplicate = nums;
    sort(nums.begin(),nums.end());

    int number = nums[0];
    int mode = number;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<n; i++)
    {
        if (nums[i] == number) 
            ++count;
        
        else
        { 
                if (count > countMode) 
                {
                    countMode = count; 
                    mode = number;
                }
            count = 1; 
            number = nums[i];
        }
    }  
    if(n == 1)
        return -1;
    int valLeft = 0;
    for(int i = 0; i < n ; i++){
        if(nums[i] == mode)
            valLeft ++;
        if(valLeft * 2 > i + 1 && (countMode - valLeft) * 2 > (n - i -1) )return i;
    }
    return -1;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    vector<int>  numduplicate;
    int n = nums.size();
    numduplicate = nums;
    sort(numduplicate.begin(),numduplicate.end());

    int number = numduplicate[0];
int mode = number;
int count = 1;
int countMode = 1;

for (int i=1; i<n; i++)
{
    cout<< nums[i]<< endl;
    if (numduplicate[i] == number) 
    {
        count++;
    }
    else
    {
        if (count > countMode) 
        {
            countMode = count;
            mode = number;
        }
        count = 1;
        number = numduplicate[i];
    }
}
    //cout << number << count;
    if(n == 1)
        cout<< -1;
    int valLeft = 0;
    for(int i = 0; i < n ; i++){
        if(nums[i] == mode)
            valLeft ++;
        if(valLeft * 2 > i + 1 && (countMode - valLeft) * 2 > (n - i -1) )cout<< i;
    }
    cout<< -1;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie();
}
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int maxAnswer = 0;
    for (int i = 0; i< flowerbed.size(); i++){
        if((i-1 < 0 || flowerbed[i-1] == 0) && (i+1 == flowerbed.size() || flowerbed[i-1] == 0)){
            maxAnswer ++;
        }
    }        
    if(n <= maxAnswer)
        return true;
    else
        return false;    
}
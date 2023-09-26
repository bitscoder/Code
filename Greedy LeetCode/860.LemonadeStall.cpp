#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
int main(){
}
bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                fives++;
            }else if(bills[i] == 10){
                if(fives == 0)
                    return false;
                else fives--;
                tens++;
            }else {
                cout<< fives<<tens<<endl;
                if(fives == 0)
                    return false;
                else if(tens == 0 && fives < 3)
                            return false;
                else if(tens == 0 && fives >= 3)
                            fives -= 3;
                else
                    fives--, tens--; 
            }
        } 
        return true;     
    }

#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 
void rec(vector<int>& ratings, int i, int j, vector<int>& assign){
    if(i < j){
        cout<< i<< j<< endl;
        int m = (i+j)/2;
        cout<< m << endl;
        rec(ratings, i, m, assign);
        rec(ratings, m+1, j, assign);
        if(ratings[m] > ratings[m+1] && assign[m] <= assign[m+1]){
            assign[m] = assign[m+1] + 1;
            int currElement = ratings[m];
            int currAssign = assign[m];
            for(int k = m - 1; k>= i; k--){
                if(ratings[k] > currElement)
                    assign[k] = currAssign + 1;
                else  if (ratings[k] == currElement)
                        assign[k] = currAssign;
                else break;
                currElement = ratings[k];
                currAssign = assign[k];
            }
        }else if (ratings[m] < ratings[m+1] && assign[m] >= assign[m+1]){
            assign[m+1] = assign[m] + 1;
            int currElement = ratings[m+1];
            int currAssign = assign[m+1];
            for(int k = m+2; k <= j; k++){
                if(ratings[k] > currElement)
                    assign[k] = currAssign + 1;
                else  if (ratings[k] == currElement)
                        assign[k] = currAssign;
                else break;
                currElement = ratings[k];
                currAssign = assign[k];
            }
        }
        /*else  if(ratings[m] == ratings[m+1] && assign[m] < assign[m+1]){
            assign[m] = assign[m+1];
            int currElement = ratings[m];
            int currAssign = assign[m];
            for(int k = m - 1; k>= i; k--){
                if(ratings[k] > currElement)
                    assign[k] = currAssign + 1;
                else  if (ratings[k] == currElement)
                        assign[k] = currAssign;
                else break;
                currElement = ratings[k];
                currAssign = assign[k];
            }
        }else if (ratings[m] == ratings[m+1] && assign[m] > assign[m+1]){
            assign[m+1] = assign[m];
            int currElement = ratings[m+1];
            int currAssign = assign[m+1];
            for(int k = m+2; k <= j; k++){
                if(ratings[k] > currElement)
                    assign[k] = currAssign + 1;
                else  if (ratings[k] == currElement)
                        assign[k] = currAssign;
                else break;
                currElement = ratings[k];
                currAssign = assign[k];
            }
        }*/
    }
}
int candy(vector<int>& ratings) {
     int n = ratings.size();
     vector<int> assign(n, 1);
     rec(ratings, 0, n-1, assign);
     int sum = 0;
     for(int i = 1; i < n-1; i++)
        if(ratings[i] == ratings[i+1] && ratings[i] == ratings[i-1]) assign[i] = 1;
        
     
     for(int i =0; i<n; i++)   sum += assign[i];
     return sum;
}
int main(){
    vector<int> ratings;
    ratings.push_back(1);
    ratings.push_back(3);
    ratings.push_back(2);
    ratings.push_back(2);
    ratings.push_back(1);
    cout << candy(ratings);
}


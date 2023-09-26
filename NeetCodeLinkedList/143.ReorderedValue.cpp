#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
        int val;
        ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* prev =  NULL;
        ListNode* curr = head;
        int i = 0;
        while (curr != NULL){
            ListNode* forwordNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forwordNode;
            i++;
        }
        curr = head;
        ListNode* iterNode = head;
        ListNode* ans = iterNode;

        i /=2;
        while (i != 0) {
            cout << i << endl;
            iterNode->next = new ListNode(curr->val);
            curr = curr->next;
            iterNode->next->next = new ListNode(prev->val);
            prev = prev->next;
            iterNode = iterNode->next->next;
            i--;
        }
        if(i%2==1){
            iterNode->val = curr->val;
        }
        head = ans;
    }
};

bool isAcronym(vector<string>& words, string s) {
    if(s.size() != words.size()){
        return false;
    }

    for(int i = 0; i< s.size(); i++){
        if(s[i] != words[i][0])
        return false;
    }    
    return true;    
}
int minimumSum(int n, int k) {

    vector<int> ans;
    int k = 0;
    for(int i = 1; i <= k/3; i++){
        ans.push_back(i);
    }
    int c = ans.size();
    for(int i = k; i < k + (n - c); i++){
        ans.push_back(i);
    }
    int sum = 0;
    for(auto it: ans){
        sum += it;
    }
    return sum;
}
// 6
// 1, 5
// 2, 4
// 3, 3

//7
// 1,6
// 2,5
// 3,4

// 4
// 1, 3
// 2, 2
// 4
// 5
// 6

static bool check(vector<int> & a, vector<int>& b){
    return a[1] < b[1];
}
int dp(vector<vector<int>>& offers, int i,vector<int> phe,vector<int>& dp1){

        if(dp1[i] != -1)return dp1[i];

        int ans1 ;
        if( i - 1 >= 0){
            int ans = dp(offers, i - 1, phe, dp1);
            if(phe[i] == -1){
                ans1 = max(ans, offers[i][2]);
            }else{
                ans1 = max(ans, offers[i][2]+ dp(offers, phe[i], phe, dp1));
            }
        }else{
            ans1 = offers[i][2];
        }
        dp1[i] = ans1;
        return ans1;
}
int binary(vector<vector<int>>& offers, int i, int j, int target){
    if(i < j){
        int m = (i + j)/2;
        
        if(target <= offers[m][1]){
            int s = binary(offers, i, m, target);
            if(target == offers[m][1]){
                return s;
            }
            else if(target < offers[m][1]){
                return max(m, s);
            }
        }else {
            return binary(offers, m + 1, j, target);
        }
        
    }return -1;
}
int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    sort(offers.begin(), offers.end(), check);

    vector<int> phe(offers.size(), -1);

    for(int i = offers.size() - 1; i >= 0; i--){
        //for(int j = i - 1 ; j >= 0; j--){
        //    if(offers[i][0] > offers[j][1]){
        //        phe[i] = j;
        //       break;
        //    }
        //}
        phe[i] = binary(offers, 0, offers.size() - 1, offers[i][0]);

    }
    for(auto it : phe){
        cout << it << endl;
    }
    vector<int> dp1(offers.size(), -1) ;
    return dp(offers, offers.size() - 1,phe, dp1);

}


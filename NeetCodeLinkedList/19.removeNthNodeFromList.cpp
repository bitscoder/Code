#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<string>> infoVector;
    for(int i =0; i < n; i++){
        vector<string> temp;
        //cin.getline()
    }





    return 0;
}

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *it = head;
        ListNode *prev = new ListNode();
        ListNode *aft = new ListNode();
        while(it->next){
            if(n == 0)
                prev = it;
            if(n == 2)
                aft = it;
            it = it->next;
            n--;
        }
        if(prev){
            return aft;
        }
        if(aft){
            prev->next = aft;
        }
        return head;
    }
};

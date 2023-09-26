#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *ansNode;
    ListNode *iterNode = ansNode;
    while (l1 != nullptr && l2 != nullptr)
    {
        int currValue = l1->val + l2->val + carry;
        carry = currValue / 10;
        iterNode->next = new ListNode(currValue % 10);
        iterNode = iterNode->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr)
    {
        int currValue = l1->val + carry;
        carry = currValue / 10;
        iterNode->next = new ListNode(currValue % 10);
        iterNode = iterNode->next;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        int currValue = l2->val + carry;
        carry = currValue / 10;
        iterNode->next = new ListNode(currValue % 10);
        iterNode = iterNode->next;
        l2 = l2->next;
    }
    return ansNode->next;
}
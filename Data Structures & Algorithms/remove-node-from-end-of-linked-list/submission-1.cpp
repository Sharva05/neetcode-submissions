/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        for(int i  = 1; i <= n; i++) end = end->next;

        ListNode* remove = head, *prev = nullptr;
        while(end) {
            end = end->next;
            prev = remove;
            remove = remove->next;
        }
        if(prev) prev->next = remove->next;
        else head = head->next;
        return head;
    }
};

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
    void reorderList(ListNode* head) {
        if(head->next == nullptr || head->next->next == nullptr) return;
        ListNode *fast = head, *slow = head, *prev = slow;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;
        ListNode *cur = slow, *ahead = slow;
        slow=nullptr;
        while(cur) {
            ahead = ahead->next;
            cur->next = slow;
            slow = cur;
            cur = ahead;
        }
        prev = head->next, cur = head;
        while(prev) {
            cur->next = slow;
            cur = cur->next;
            slow = slow->next;
            cur->next = prev;
            cur = cur->next;
            prev = prev->next;
        }
        if(slow) cur->next = slow;
    }
};

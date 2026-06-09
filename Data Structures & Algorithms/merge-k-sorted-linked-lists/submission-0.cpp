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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
         return divide(lists, 0, lists.size()-1);
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if(l == r) return lists[l];
        int m = l + (r - l) / 2;
        ListNode* LEFT = divide(lists, l, m);
        ListNode* RIGHT = divide(lists, m + 1, r);
        return conquer(lists, LEFT, RIGHT);
    }

    ListNode* conquer(vector<ListNode*>& lists, ListNode* LL1, ListNode* LL2) {
        ListNode dummy = ListNode();
        ListNode* cur = &dummy;
        while(LL1 && LL2) {
            if(LL1->val <= LL2->val) {
                cur->next = LL1;
                cur = cur->next;
                LL1 = LL1->next;
            }
            else {
                cur->next = LL2;
                cur = cur->next;
                LL2 = LL2->next;
            }
        }
        if(LL1) cur->next = LL1;
        else cur->next = LL2;
        return dummy.next;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node *cur=head, *copy=nullptr;
        while(cur) {
            copy= new Node(cur->val);
            copy->next=cur->next;
            cur->next=copy;
            cur=copy->next;
        }

        cur=head, copy=head->next;

        
        while(cur) {
            if(cur->random) copy->random=cur->random->next;
            cur=copy->next;
            if(cur) copy=cur->next;
        }

        cur=head, copy=head->next;
        Node *ans=copy;

        while(cur) {
            cur->next=copy->next;
            cur=cur->next;
            if(cur) {
                copy->next=cur->next;
                copy=copy->next;
            }
        }

        return ans;
    }
};

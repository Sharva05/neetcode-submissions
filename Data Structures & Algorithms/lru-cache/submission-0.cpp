class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int a, int b) {
        key=a;
        value=b;
        prev=nullptr;
        next=nullptr;
    }
};

class LRUCache {
    int cap;
    unordered_map<int, Node*>m;
    Node* dummy=new Node(-1, -1);
    Node* tail=new Node(-1, -1);
public:
    LRUCache(int capacity) {
        cap=capacity;
        dummy->next = tail;
        tail->prev = dummy;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;

        Node *n = m[key];
        remove(n);
        toBack(n);

        return n->value;
    }
    
    void put(int key, int value) {
        Node *n=nullptr;

        if(m.find(key)!=m.end()) {
            n=m[key];
            remove(n);
            n->value=value;
        }
        else {
            n=new Node(key, value);
            m[key]=n;

            if(m.size() > cap) {
                Node* del=dummy->next;
                m.erase(del->key);
                remove(del);
                delete(del);
            }
        }

        toBack(n);
    }

    void remove(Node* n) {
        n->prev->next=n->next;
        n->next->prev=n->prev;
    }
    void toBack(Node* n) {
        n->next=tail;
        n->prev=tail->prev;
        tail->prev->next=n;
        tail->prev=n;
    }
};
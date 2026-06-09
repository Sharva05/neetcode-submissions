class TrieNode {
public:
    unordered_map<char, TrieNode*> map;
    bool endOfWord = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(!cur->map[c]) {
                cur->map[c] = new TrieNode();
            }
            cur = cur->map[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(!cur->map[c]) return false;
            cur = cur->map[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix) {
            if(!cur->map[c]) return false;
            cur = cur->map[c];
        }
        return true;
    }
};

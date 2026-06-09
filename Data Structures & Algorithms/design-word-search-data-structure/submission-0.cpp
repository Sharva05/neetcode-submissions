
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord ;
    TrieNode() : endOfWord(false) {}
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode() ;
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(cur->children.find(c) == cur->children.end()) cur->children[c] = new TrieNode;
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, root, 0);
    }
    
    bool dfs(string& word, TrieNode* root, int i) {
        for(int j = i; j < word.length(); j++) {
            char c = word[j];
            if(c == '.') {
                for(auto it : root->children) {
                    if(dfs(word, it.second, j + 1)) return true;
                }
                return false;
            }
            if(root->children.find(c) == root->children.end()) return false;;
            root = root->children[c];
        }
        return root->endOfWord;
    }
};



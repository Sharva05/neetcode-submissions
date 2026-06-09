class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode() : endOfWord(false) {}
};

class Solution {
    TrieNode* root = new TrieNode();
    vector<string> ans;
    string temp = "";
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string s : words) addWord(s);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, temp);
            }
        }
        return ans;
    }

    void addWord(string& word) {
        TrieNode* cur = root;
        for(char c : word) {
            if(cur->children.find(c) == cur->children.end()) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, string& temp) {
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || root->children.find(board[i][j]) == root->children.end()) {
            return;
        }
        temp.push_back(board[i][j]);
        char clone = board[i][j];
        board[i][j] = '#';
        root = root->children[clone];
        if(root->endOfWord) {
            ans.push_back(temp);
            root->endOfWord = false;
        }
        dfs(board, i + 1, j, root, temp);
        dfs(board, i - 1, j, root, temp);
        dfs(board, i, j + 1, root, temp);
        dfs(board, i, j - 1, root, temp);
        board[i][j] = clone;
        temp.pop_back();
        return;
    }
};
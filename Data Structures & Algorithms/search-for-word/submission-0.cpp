class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int flag = 0;
        for(int row = 0; row < board.size(); row++) {
           for(int col = 0; col < board[0].size(); col++) {
                if(backtracking(board, word, row, col, 0)) flag = 1;
           }
        }
        return flag == 1;
    }
    bool backtracking(vector<vector<char>>& board, string& word, int i, int j, int letter) {
        if(i == board.size() || j == board[0].size() || i < 0 || j < 0 || word[letter] != board[i][j]){
            return false;
        }
        if(letter == word.size() - 1) return true;
        return backtracking(board, word, i - 1, j, letter + 1) ||
        backtracking(board, word, i + 1, j, letter + 1) ||
        backtracking(board, word, i, j + 1, letter + 1) ||
        backtracking(board, word, i, j - 1, letter + 1);
        
    }
};

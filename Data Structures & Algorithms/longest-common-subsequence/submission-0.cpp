class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> prev(text2.size() + 1, 0);
        vector<int> cur;

        for(int i = text1.size() - 1; i >= 0; i--) {
            cur = prev;
            for(int j = text2.size() - 1; j >= 0; j--) {
                if(text1[i] == text2[j]) cur[j] = 1 + prev[j + 1];
                
                else cur[j] = max(cur[j + 1], prev[j]);
            }
            prev = cur;
        }
        return cur[0];
    }
};
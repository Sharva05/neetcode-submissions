class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); 
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        int maxWordLen = 0;
        for(const string& s : wordDict) maxWordLen = max(maxWordLen, (int)s.length());
        
        for(int i = 1; i < dp.size(); i++) {
            for(int j = i - 1; j >= i - maxWordLen && j >= 0; j--) {
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[dp.size() - 1];
    }
};
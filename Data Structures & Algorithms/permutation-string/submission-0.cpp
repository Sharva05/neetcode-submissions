class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(char c : s1) freq[c - 'a']++;

        int len = 0;
        vector<int> temp = freq;
        for(int i = 0; i < s2.size(); i++) {
            int c = s2[i] - 'a';
            if(temp[c] != 0) {
                temp[c]--;
                len++;
                if(len == s1.size()) return true;
            }
            else {
                len = 0;
                temp = freq;
            }
        }
        return false;
    }
};

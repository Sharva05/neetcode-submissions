class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++) {
            if(s1Freq == s2Freq) return true;
            s2Freq[s2[l++] - 'a']--;
            s2Freq[s2[r] - 'a']++;
        }
        return s1Freq == s2Freq;
    }
};

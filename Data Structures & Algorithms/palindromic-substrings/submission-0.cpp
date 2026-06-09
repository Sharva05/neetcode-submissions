class Solution {
public:
    int countSubstrings(string s) {
        int total = 0;
        for(int i = 0; i < s.size(); i++){
            int l = i, r = i;
            while(l >=0 && r < s.size() && s[l] == s[r]) {
                total++;
                l--;
                r++;
            }
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
                total++;
            }
        }
        return total;
    }
};

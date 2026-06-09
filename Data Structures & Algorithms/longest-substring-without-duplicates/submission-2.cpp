class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0,l=0,r=0;
        unordered_set<int>st;
        while(r<s.length()) {
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            r++;
            longest=max(longest,r-l);
        }
        return longest;   
    }
};

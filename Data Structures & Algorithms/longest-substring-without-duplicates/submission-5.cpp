class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0,l=0,r=0;
        unordered_map<char,int>charInd(26);
        while(r<s.length()) {
            if(charInd.find(s[r])!=charInd.end() && charInd[s[r]]>=l){
                l=charInd[s[r]]+1;
            }
            charInd[s[r]]=r;
            r++;
            longest=max(longest,r-l);
        }
        return longest;   
    }
};

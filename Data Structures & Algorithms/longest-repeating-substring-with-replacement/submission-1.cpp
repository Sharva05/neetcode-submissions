class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>frq;
        int l=0,r=0,lng=0,maxf=0;
        while(r<s.length()){
            frq[s[r]]++;
            maxf=max(maxf, frq[s[r]]);
            if((r-l)+1 - maxf>k){
                frq[s[l]]--;
                l++;
            }
            else lng = max(lng, (r-l)+1);
            r++;
        }
        return lng;
    }
};

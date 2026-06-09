class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>frq;
        int l=0,r=0,lng=0;
        while(r<s.length()){
            frq[s[r]]++;
            r++;
            if((r-l) - frq[s[l]] <= k){
                lng = max(lng, r-l);
            }
            else{
                frq[s[l]]--;
                l++;
            }
        }
        return lng;
    }
};

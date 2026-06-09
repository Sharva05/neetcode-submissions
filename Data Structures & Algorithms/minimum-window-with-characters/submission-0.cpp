class Solution {
public:
    string minWindow(string s, string t) {
        int tLen=t.length(),sLen=s.length();
        if(tLen>sLen) return "";

        int small=sLen,l=0,a=0;
        unordered_multiset<char>T{t.begin(),t.end()};
        unordered_multiset<char>S;
        unordered_map<char,int>F;
        for(int r=0;r<sLen;r++){
           
            while(T.size()==S.size()){
                auto it=S.find(s[l]);
                if(it != S.end() && F[s[l]]--==0)
                    S.erase(it);
                if(r-l < small){
                    small=r-l;
                    a=l;
                }
                l++;
            }
            if(T.count(s[r])>S.count(s[r])){
                S.insert(s[r]);
            }
            if(T.find(s[r])!=T.end()){
                F[s[r]]++;
            }
        }
        return s.substr(a,small);
    }
};

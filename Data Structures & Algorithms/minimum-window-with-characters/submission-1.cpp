class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()) return "";

        int mark=-1,l=0,distance=s.length();
        unordered_map<char,int>T;
        unordered_map<char,int>F;
        
        for(char c : t) T[c]++;
        
        for(int r=0;r<s.length();r++){
            if(T[s[r]]!=0)
                F[s[r]]++;
            int flag=1;
            for(char c: t){
                if(T[c]>F[c]){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                while(F[s[l]]==0){
                    l++;
                }
                if(distance>=r-l+1){
                    distance=r-l+1;
                    mark=l;
                }
                F[s[l]]--;
                l++; 
            }   
        }
        if(mark==-1) return "";
        return s.substr(mark,distance);
    }
};

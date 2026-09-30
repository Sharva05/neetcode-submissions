class Solution {
    int getVal(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        int res=getVal(s[s.size()-1]);
        for(int i=0; i<s.size()-1; i++){
            if( getVal(s[i]) < getVal(s[i+1] )) res-=getVal(s[i]);
            else res+= getVal(s[i]);
        }
        return res;
    }
};
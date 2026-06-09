class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for(char c:s){
            if(isalnum(c)) newStr+=tolower(c);
        }
        int l=0, r=newStr.length()-1;
        while(l<r && newStr[l] == newStr[r]){
            l++;
            r--;
        }
        if(l<r)
            return false;
        return true;
    }
};

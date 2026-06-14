class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string prefix="", leftString=strs[0], rightString=strs[strs.size()-1];
        int minLen=min(leftString.size(), rightString.size());
        for(int i=0; i<minLen; i++){
            if(leftString[i]==rightString[i]) prefix+=leftString[i];
            else break;
        }
        return prefix;
    }
};
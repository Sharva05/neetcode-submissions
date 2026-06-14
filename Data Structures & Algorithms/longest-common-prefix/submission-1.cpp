class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefixLen =INT_MAX;
        for(int i=0; i<strs.size()-1; i++){
            int curLen=0;
            while(curLen<strs[i].size() && curLen<strs[i+1].size() && curLen<prefixLen && strs[i][curLen]==strs[i+1][curLen])
                curLen++;

            prefixLen=curLen;
        }
        return strs[0].substr(0, prefixLen);
    }
};
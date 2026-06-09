class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mp;
        for(string s : strs){
            vector<int>freq(26,0);
            for(char c : s)
                freq[c - 'a']++;
            string freqStr="";
            for(int i : freq)
                freqStr+=to_string(i);
            mp[freqStr].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it:mp)
            result.push_back(it.second);
        return result;
    }
};

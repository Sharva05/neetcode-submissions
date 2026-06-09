class Solution {
public:
    bool isValid(string s) {
        vector<char>S;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == '(') S.push_back(')');
            else if (c == '[') S.push_back(']');
            else if (c == '{') S.push_back('}');
            else {
                if(S.empty() || S.back() != c) return false;
                else S.pop_back();
            }
        }
        return S.size() == 0;
    }
};

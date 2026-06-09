class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int total = 1;
        for(int i = 0; i < s.size(); i++) {
            int oneDigit = stoi(s.substr(i, 1));
            if(oneDigit != 0 && i != s.size() - 1) {
                int twoDigit = stoi(s.substr(i, 2));
                if(twoDigit <= 26) total++;
            }
        }
        return total;
    }
};

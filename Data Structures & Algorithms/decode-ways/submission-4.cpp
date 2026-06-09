class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int prev = 1, prev2 = 1, siz = s.size();
        for(int i = 1; i < siz; i++) {
            int twoDigit = stoi(s.substr(i - 1, 2));
            int cur = 0;
            if(s[i] != '0') cur = prev;
            if(twoDigit >= 10 && twoDigit <= 26) cur += prev2;
            prev2 = prev;
            prev =cur;
        }
        return prev;
    }
};

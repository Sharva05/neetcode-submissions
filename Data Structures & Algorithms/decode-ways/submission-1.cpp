class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int prev = 1, prev2 = 1, siz = s.size();
        for(int i = 1; i < siz; i++) {
            int twoDigit = stoi(s.substr(i - 1, 2));
            int temp = 0;
            if(s[i] != '0') temp += prev;
            if(twoDigit <= 26) temp += prev2;
            prev2 = prev;
            prev =temp;
        }
        return prev;
    }
};

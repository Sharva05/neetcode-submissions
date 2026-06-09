class Solution {
public:
    vector<int>res;
    vector<int> countBits(int n) {
        for(int i = 0 ; i <= n; i++) {
            helper(i);
        }
        return res;
    }
    void helper(int n) {
        int count = 0;
        while(n) {
            count += n & 1;
            n >>= 1;
        }
        res.push_back(count);
    }
};

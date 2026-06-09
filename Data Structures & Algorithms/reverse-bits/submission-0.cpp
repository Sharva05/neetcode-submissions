class Solution {
public:
    int reverseBits(int n) {
        int res = 0, temp = 0;
        for(int i = 0; i < 32; i++) {
            res <<= 1;
            res = res | (n % 2);
            n >>= 1;
        }
        return res;
    }
};
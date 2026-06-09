class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0, temp = 0;
        for(int i = 0; i < 32; i++) {
            res <<= 1;
            res = res | (n % 2);
            n >>= 1;
        }
        return res;
    }
};

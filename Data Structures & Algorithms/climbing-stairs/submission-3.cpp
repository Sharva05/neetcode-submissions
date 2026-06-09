class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int plus2 = 1, plus1 = 1, cur = 1;
        for(int i = n - 2; i >= 0; i--) {
            cur = plus1 + plus2;
            plus2 = plus1;
            plus1 = cur;
        }
        return cur;
    }
};

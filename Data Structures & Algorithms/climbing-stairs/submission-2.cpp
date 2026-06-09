class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int> numWays(n + 1, 0);
        numWays[n]++;
        numWays[n - 1]++;
        int total = 2;
        for(int i = n - 2; i >= 0; i--) {
            numWays[i] = numWays[i + 1] + numWays[i + 2];
        }
        return numWays[0];
    }
};

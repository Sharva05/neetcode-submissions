class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> belowRow(n, 1);

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                belowRow[j] += belowRow[j + 1];
            }
        }
        return belowRow[0];
    }
};

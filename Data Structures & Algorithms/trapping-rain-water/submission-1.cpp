class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
            rightMax[n- 1 - i] = max(rightMax[n - i], height[n - i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            int minHeight = min(leftMax[i], rightMax[i]);
            if(height[i] < minHeight)
                res+= minHeight - height[i];
        }
        return res;
    }
};
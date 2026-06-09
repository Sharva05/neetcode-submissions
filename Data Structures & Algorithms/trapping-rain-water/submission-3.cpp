class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), leftMax = height[0], rightMax = height[n - 1],l = 0, r = n - 1, res = 0;
        while(l <= r) {
            if(leftMax < rightMax) {
                if(height[l] >= leftMax) leftMax = height[l++];
                else res += leftMax - height[l++];
            }
            else {
                if(height[r] >= rightMax) rightMax = height[r--];
                else res += rightMax - height[r--];
            }
        }
        return res;
    }
};
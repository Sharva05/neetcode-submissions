class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, left = 0, temp = 0;
        for(int i = 0; i < height.size(); i++) {
            if(height[i] >= left) {
                left = height[i];
                area += temp;
                temp = 0;
            }
            else {
                temp += left - height[i];
            }
        }
        temp = 0;
        int right = 0;
        for(int i = height.size() - 1; i >= 0 ; i--) {
            if(height[i] > right) {
                right = height[i];
                area += temp;
                temp = 0;
            }
            else {
                temp += right - height[i];
            }
        }
        return area;
    }
};
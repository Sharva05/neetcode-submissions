class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distanceSum = 0, i = 0;
        while(i <= distanceSum && distanceSum < nums.size() - 1) {
            distanceSum = max(distanceSum, i + nums[i]);
            i++;
        }
        return distanceSum >= nums.size() - 1 ? true : false;
    }
};

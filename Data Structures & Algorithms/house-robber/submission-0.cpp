class Solution {
public:
    int rob(vector<int>& nums) {
        int robAllowed = nums[0], robNotAllowed = max(nums[0], nums[1]), cur;
        for(int i = 2; i < nums.size(); i++) {
            cur = max(robAllowed + nums[i], robNotAllowed);
            robAllowed = robNotAllowed;
            robNotAllowed = cur;
        }
        return cur;
    }
};

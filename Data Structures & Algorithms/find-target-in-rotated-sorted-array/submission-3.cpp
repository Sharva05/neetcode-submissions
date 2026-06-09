class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) {
                if(nums[m] > nums[l] && target < nums[l]) l = m + 1;
                else r = m - 1;
            }
            else {
                if(nums[r] > nums[m] && target > nums[r]) r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
};

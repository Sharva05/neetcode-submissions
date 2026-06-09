class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l)/2, n = nums[mid];
            if(n == target) return mid;
            else if(n < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
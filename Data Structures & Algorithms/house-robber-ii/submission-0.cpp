class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        return max(helper(v1), helper(v2));

    }
private:
    int helper(vector<int>& vec) {
        int allowed = 0, notAllowed = 0;
        for(int i = 0; i < vec.size(); i++) {
            int temp = max(vec[i] + allowed, notAllowed);
            allowed = notAllowed;
            notAllowed = temp;
        }
        return notAllowed;
    }
};

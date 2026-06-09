class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0], mini = nums[0], result = maxi;
        for(int i = 1; i < nums.size(); i++) {
            int temp_maxi = maxi;
            
            maxi = max(nums[i], max(maxi * nums[i], mini * nums[i]));
            mini = min(nums[i], min(temp_maxi * nums[i], mini * nums[i]));
            result = max(result, maxi);
        }
        return result;
    }
};

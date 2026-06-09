class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0], mini = nums[0], result = maxi;
        for(int n : nums) {
            int temp_maxi = maxi;
            
            maxi = max(n, max(maxi * n, mini * n));
            mini = min(n, min(temp_maxi * n, mini * n));
            result = max(result, maxi);
        }
        return maxi;
    }
};

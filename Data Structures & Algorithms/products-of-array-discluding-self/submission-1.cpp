class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l =nums.size();
        vector<int>prefix(l, 1);
        for(int i=1;i<l; i++){
            prefix[i] = nums[i-1] * prefix [i - 1];
        }
        int suffix=1;
        for(int i = l-1; i>=0 ; i--){
            prefix[i]*= suffix;
            suffix*=nums[i];
        }
        return prefix;
    }
};

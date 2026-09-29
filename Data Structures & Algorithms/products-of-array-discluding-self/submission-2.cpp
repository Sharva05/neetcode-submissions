class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        int pre=1;
        for(int i=0; i<nums.size(); i++){
            prefix[i]=pre;
            pre*=nums[i];
        }
        int suf=1;
        for(int i=nums.size()-1; i>=0; i--){
            prefix[i]*=suf;
            suf*=nums[i];
        }
        return prefix;
    }
};

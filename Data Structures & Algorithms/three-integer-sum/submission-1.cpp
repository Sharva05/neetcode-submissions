class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0; i<nums.size()-2; i++){
            int l=i+1, r=nums.size()-1;
            while(l < r){
                int sum = nums[i]+ nums[l] + nums[r];
                if(sum == 0) res.push_back({nums[i], nums[l], nums[r]});
                if(sum > 0 || sum == 0){
                    while (nums[r]==nums[r+1]) r--;
                    r--;
                }
                if(sum < 0 || sum ==0 ){
                    while(nums[l+1]==nums[l]) l++;
                    l++;
                }
            }
            while i<nums.size()-2 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};

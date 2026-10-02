class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> t;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) break;

            if(i>0 && nums[i]==nums[i-1]) continue;

            int l=i+1, r=nums.size()-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r];
                if(s==0){
                    t.push_back({nums[i], nums[l], nums[r]});
                    
                    while(l<r && nums[l]==nums[l+1])l++;
                    l++;
                    while(l<r && nums[r-1]==nums[r]) r--;
                    r--;
                }

                else if(s<0) l++;
                
                else r--;
            }
        }
        return t;
    }
};

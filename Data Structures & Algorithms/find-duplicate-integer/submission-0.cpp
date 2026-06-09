class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0], fast=nums[nums[0]];

        while(slow!=fast) {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        int ans=0;
        while(ans!=slow) {
            ans=nums[ans];
            slow=nums[slow];
        }

        return ans;
    }
};

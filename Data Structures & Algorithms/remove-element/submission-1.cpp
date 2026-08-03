class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=nums.size(), i=0;
        while(i<l){
            if(nums[i]==val) swap(nums[i], nums[--l]);
            else i++;
        }
        return i;
    }
};
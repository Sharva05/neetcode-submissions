class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l =nums.size();
        vector<int>prefix(l, 1);
        vector<int>suffix(l,1);
        vector<int>ans(l,1);
        for(int i=1;i<l; i++){
            prefix[i] = nums[i-1] * prefix [i - 1];
            suffix[l - 1 - i] = nums[ l- i ] * suffix[ l - i ];
        }
        for(int i = 0;i < l ; i++){
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};

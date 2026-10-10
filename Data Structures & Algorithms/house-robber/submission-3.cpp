class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0, prev2=0;
        for(int n:nums){
            int temp=prev1;
            prev1=max(prev1, n+prev2);
            prev2=temp;
        }
        return prev1;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int n : nums){
            if(st.find(n-1)==st.end()){
                int temp=1;
                while(st.find(++n)!=st.end()) temp++;
                longest=(temp>longest)?temp:longest;
            }
        }
        return longest;
    }
};

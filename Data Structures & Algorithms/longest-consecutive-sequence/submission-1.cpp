class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_multiset<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int n : nums){
            if(st.find(n-1)!=st.end()){
                int temp=st.count(n);
                while(st.find(++n)!=st.end()) temp+=st.count(n);
                longest=(temp>longest)?temp:longest;
            }
        }
        return longest;
    }
};

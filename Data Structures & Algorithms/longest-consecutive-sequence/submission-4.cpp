class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        auto endIt = st.end();
        for(int n : st){
            if(st.find(n-1)==endIt && st.find(n+longest)!=endIt){
                int temp=1;
                while(st.find(++n)!=endIt) temp++;
                longest=(temp>longest)?temp:longest;
            }
        }
        return longest;
    }
};

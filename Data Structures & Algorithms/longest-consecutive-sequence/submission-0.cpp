class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int longest=0;
        for(int n : nums){
            int temp=1;
            if(mp[n+1]!=0){
                temp+= mp[n+1];
                mp[n]=temp;;
            }
            else{
                int x=n;
                while(st.find(++x)!=st.end())
                    temp++;
                mp[n]= temp;
            }
            longest=(temp>longest)?temp:longest;
        }
        return longest;
    }
};

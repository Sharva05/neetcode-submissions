class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<vector<int>>occ(nums.size());
        for(int n : nums){
            mp[n]++;
        }
        for(auto it : mp){
            occ[it.second - 1].push_back(it.first);
        }
        vector<int>kNums;
        for(int i= occ.size() - 1; i >=0 && kNums.size() != k; i--){
            for(int j=0; j< occ[i].size() && kNums.size() !=k;j++){
                kNums.push_back(occ[i][j]);
            }
        }
        return kNums;
    }
};

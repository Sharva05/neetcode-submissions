class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backtracking(nums, target, 0, 0, temp);
        return ans;
    }

    void backtracking(vector<int>& nums, int& target, int sum, int i, vector<int>& temp) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        if(i >= nums.size() || sum > target) {
            return;
        }
        temp.push_back(nums[i]);
        backtracking(nums, target, sum + nums[i], i, temp);
        temp.pop_back();
        backtracking(nums, target, sum, i + 1, temp);
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(auto& interval : intervals) {
            if(res.empty() || interval[0] > res.back()[1]) res.push_back(interval);
            else res.back()[1] = max(interval[1], res.back()[1]);
        }
        return res;
    }
};

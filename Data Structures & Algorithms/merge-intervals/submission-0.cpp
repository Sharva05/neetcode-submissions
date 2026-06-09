class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size()) {
            if(res.empty() || intervals[i][0] > res.back()[1]) res.push_back(intervals[i]);
            else res.back()[1] = max(intervals[i][1], res.back()[1]);
            i++;
        }
        return res;
    }
};

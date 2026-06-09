class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int lastEnd = 0, count = 0;
        for(auto& interval : intervals) {
            if(interval[0] < lastEnd) count++;
            else lastEnd = max(lastEnd, interval[1]);
        }
        return count;
    }
};

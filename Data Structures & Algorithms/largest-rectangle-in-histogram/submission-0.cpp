class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int area = 0, idx = 0, i;
        for(i = 0 ; i < heights.size(); i++) {
            idx = i;
            while(!s.empty() && heights[i] < s.top().first) {
                area = max(area, (i - s.top().second) * s.top().first);
                idx = s.top().second;
                s.pop();
            }
            s.push({heights[i], idx});
        }
        while(!s.empty()) {
                area = max(area, (i - s.top().second) * s.top().first);
                s.pop();
            }
        return area;
    }
};
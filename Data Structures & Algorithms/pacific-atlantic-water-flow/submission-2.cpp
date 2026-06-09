class Solution {
    bool pacific, atlantic;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                pacific = false;
                atlantic = false;
                dfs(heights, i, j, heights[i][j]);
                if(pacific && atlantic) ans.push_back({i, j});
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, int prevHeight) {
        if(i < 0 || j < 0) {
            pacific = true;
            return;
        }
        if(i == heights.size() || j == heights[0].size()) {
            atlantic = true;
            return;
        }
        if(heights[i][j] > prevHeight) return ;
        int temp = heights[i][j];
        heights[i][j] = INT_MAX;
        for(auto& dir : directions) {
            dfs(heights, i + dir[0], j + dir[1], temp);
            if(pacific && atlantic) break;
        }
        heights[i][j] = temp;
    }
};

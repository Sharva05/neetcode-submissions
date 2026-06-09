class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int l = heights.size();
        int b = heights[0].size();
        vector<vector<bool>> pacific(l, vector<bool> (b));
        vector<vector<bool>> atlantic(l, vector<bool> (b));
        vector<vector<int>> both;
        for(int i = 0; i < l; i++) {
            dfs(heights, pacific, 0, i, 0);
            dfs(heights, atlantic, 0, i, b - 1);
        }
        for(int j = 0; j < b; j++) {
            dfs(heights, pacific, 0, 0, j);
            dfs(heights, atlantic, 0, l - 1, j);
        }
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < b; j++) {
                if(pacific[i][j] && atlantic[i][j]) both.push_back({i, j});
            }
        }
        return both;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int prevHeight, int i, int j) {
        if(i < 0 || i >= heights.size() || j < 0 || j>= heights[0].size() || heights[i][j] < prevHeight || ocean[i][j] == true) return;
        ocean[i][j] = true;
        dfs(heights, ocean, heights[i][j], i + 1, j);
        dfs(heights, ocean, heights[i][j], i - 1, j);
        dfs(heights, ocean, heights[i][j], i, j + 1);
        dfs(heights, ocean, heights[i][j], i, j - 1);
    }
};
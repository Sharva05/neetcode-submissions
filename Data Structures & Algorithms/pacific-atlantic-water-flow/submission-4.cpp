class Solution {
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& O, int i, int j, int h){
        if(i<0 || i==heights.size() || j<0 || j==heights[0].size() || h>heights[i][j] || O[i][j]==true) return;
        O[i][j]=true;
        dfs(heights, O, i-1, j, heights[i][j]);
        dfs(heights, O, i+1, j, heights[i][j]);
        dfs(heights, O, i, j-1, heights[i][j]);
        dfs(heights, O, i, j+1, heights[i][j]);
        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> P(heights.size(), vector<bool> (heights[0].size()));
        vector<vector<bool>> A(heights.size(), vector<bool> (heights[0].size()));
        
        vector<vector<int>> res;

        for(int i=0; i<heights.size(); i++){
            dfs(heights, P, i, 0, -1);
            dfs(heights, A, i, heights[0].size()-1, -1);
        }

        for(int j=0; j<heights[0].size(); j++){
            dfs(heights, P, 0, j, -1);
            dfs(heights, A, heights.size()-1, j, -1);
        }

        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++) if(P[i][j] && A[i][j]) res.push_back({i, j});
        }

        return res;
    }
};

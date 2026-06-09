class Solution {
public:
    int islands = 0;
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(dfs(grid, i, j)) islands++;
            }
        }
        return islands;
    }

    bool dfs(vector<vector<char>>& grid, int i, int j) {
        if(i == grid.size() || i < 0 || j == grid[0].size() || j < 0 || grid[i][j] == '0') return false;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        return true;       
    }
};

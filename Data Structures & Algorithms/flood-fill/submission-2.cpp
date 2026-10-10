class Solution {
    void dfs(vector<vector<int>>& image, int i, int j, int color, int original){
        if(i<0 || j<0 || i==image.size() || j==image[0].size() || image[i][j]!=original) return;

        image[i][j]=color;
        dfs(image, i+1, j, color, original);
        dfs(image, i-1, j, color, original);
        dfs(image, i, j+1, color, original);
        dfs(image, i, j-1, color, original);
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;

        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
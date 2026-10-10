class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0, minute=0;

        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i, j});
            }
        }

        while(!q.empty()){
            int s=q.size();
            for(int k=0; k<s; k++){
                auto r=q.front();
                q.pop();
                int i=r.first, j=r.second;
                if(i!=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    fresh--;
                    q.push({i-1, j});
                }
                if(i!=grid.size()-1 && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    fresh--;
                    q.push({i+1, j});
                }
                if(j!=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    fresh--;
                    q.push({i, j-1});
                }
                if(j!=grid[0].size()-1 && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    fresh--;
                    q.push({i, j+1});
                }
            }
            if(!q.empty()) minute++;
        }
        return (fresh==0)?minute:-1;
    }
};

class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        if(visited[i]) return;
        visited[i]=true;
        for(int j=0; j<isConnected[0].size(); j++){
            if(isConnected[i][j]) dfs(isConnected, visited, j);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int p=0;
        vector<bool> visited(isConnected.size(), false);
        for(int i=0; i<isConnected.size(); i++){
            if(visited[i]) continue;
            dfs(isConnected, visited ,i);
            p++;
        }
        return p;
    }
};
class Solution {
    void dfs(vector<vector<int>>& adj, vector<bool>& visited,int i, int& count){
        if(visited[i]) return;
        visited[i]=true;
        count++;
        for(int j=0; j<adj[i].size(); j++) dfs(adj, visited, adj[i][j], count);
        return;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()+1 != n) return false;
        
        vector<bool> visited(n, false);
        
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int count=0;
        dfs(adj, visited, 0, count);
        return count==n;
    }
};

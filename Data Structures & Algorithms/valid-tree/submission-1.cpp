class Solution {
    unordered_set<int> visited;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto pair : edges) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        return dfs(adj, -1, 0) && visited.size() == n;
    }

    bool dfs(vector<vector<int>>& adj, int prev, int i) {
        if(visited.count(i)) return false;
        visited.insert(i);
        for(int node : adj[i]) {
            if(node != prev)
               if(!dfs(adj, i, node)) return false;
        }
        return true;
    }
};

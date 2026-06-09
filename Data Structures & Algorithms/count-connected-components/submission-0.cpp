class Solution {
    int count = 0;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        for(int i = 0; i < n; i++) {
            if(dfs(adj, visited, i)) count++;
        }
        return count;
    }

    bool dfs(vector<vector<int>>& adj, unordered_set<int>& visited, int i) {
        if(visited.count(i)) return false;
        visited.insert(i);
        for(int node : adj[i]) {
            dfs(adj, visited, node);
        }
        return true;
    }
};

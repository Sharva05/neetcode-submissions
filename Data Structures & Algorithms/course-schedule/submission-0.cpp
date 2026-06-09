class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        queue<int> queue;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                queue.push(i);
            }
        }

        while(!queue.empty()) {
            int i = queue.front();
            queue.pop();
            numCourses--;
            for(int outdeg : adj[i]) {
                indegree[outdeg]--;
                if(indegree[outdeg] == 0) queue.push(outdeg);
            }
        }
        return numCourses == 0;
    }
};
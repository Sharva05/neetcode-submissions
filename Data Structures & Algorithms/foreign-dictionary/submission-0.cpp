class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for(string& s : words) {
            for(char c : s) {
                indegree[c] = 0;
            }
        }
        for(int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            int minLen = min(s1.size(), s2.size());
            if (s1.size() > s2.size() && s1.substr(0, minLen) == s2.substr(0, minLen))
                return "";
            for(int j = 0; j < minLen; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]].insert(s2[j]);
                    indegree[s2[j]]++;
                    break;
                }
            }
        }

        queue<char> queue;
        for(auto it : indegree) {
            if(it.second == 0) queue.push(it.first);
        }
        string ans = "";
        while(!queue.empty()) {
            ans += queue.front();
            for(char c : adj[queue.front()]) {
                indegree[c]--;
                if(indegree[c] == 0) queue.push(c);
            }
            queue.pop();
        }
        return indegree.size() == ans.size() ? ans : "";
    }
};

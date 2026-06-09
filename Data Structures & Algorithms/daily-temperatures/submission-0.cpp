class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int siz = temperatures.size();
        vector<int> ans(siz, 0);
        stack<int> s;
        for(int i = 0; i < siz; i++) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
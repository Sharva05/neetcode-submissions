class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> com;
        for(int i = 0; i < position.size(); i++) {
            com.push_back({position[i], speed[i]});
        }
        sort(com.begin(), com.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });
        int fleets = com.size();
        double ahead = (double)(target - com[0].first)/ com[0].second;
        for(int i = 1; i < com.size(); i++){
            double reach = (double)(target - com[i].first)/ com[i].second;
            if(reach <= ahead) {
                fleets--;
            }
            else ahead = reach;
        }
        return fleets;
    }
};
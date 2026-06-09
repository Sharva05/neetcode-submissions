class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end()) return "";
        int l = 0, r = m[key].size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(m[key][mid].first > timestamp) r = mid - 1;
            else l = mid + 1;
        }
        return r >= 0 ? m[key][r].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
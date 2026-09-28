class RandomizedSet {
    unordered_map<int, int>mp;
    vector<int>v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        mp[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int idx=mp[val];
        swap(v[idx], v[v.size()-1]);
        mp[v[idx]]=idx;
        mp.erase(v[v.size()-1]);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int r=rand()%v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
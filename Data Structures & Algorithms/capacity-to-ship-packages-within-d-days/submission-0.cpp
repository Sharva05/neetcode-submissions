class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int total_weight=0, max_element=0;
        for(int w:weights) {
            total_weight+=w;
            max_element=max(max_element, w);
        }
        int l=max_element, r=total_weight, mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(canShip(weights, days, mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
    bool canShip(vector<int>& weights,int days, int capacity){
        int count_days=0, weight_sum=0;
        for(int w:weights){
            weight_sum+=w;
            if(weight_sum>capacity){
                weight_sum=w;
                count_days++;
                if(count_days>days) return false;
            }
        }
        count_days++;
        return count_days<=days;
    }
};
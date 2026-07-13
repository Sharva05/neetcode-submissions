class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(), piles.end());
        int low=1, mid;
        while(low<high){
            mid=low+(high-low)/2;
            if(can_eat(piles, h, mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
    bool can_eat(vector<int>& piles, int h, int speed){
        long long hour=0;
        for(int n:piles){
            hour+=(n+speed-1)/speed;
            if(hour>h) return false;
        }
        return true;
    }
};
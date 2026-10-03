class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());

        while(l<=r){
            int s=l+(r-l)/2;
            long long t=0;
            for(int p:piles) t+=(p+s-1)/s;
            if(t>h) l=s+1;
            else r=s-1;
        }
        return l;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = *max_element(piles.begin(), piles.end()), l = 1, r = m, mid;
        while(l <= r) {
            mid = l + (r - l) /  2;
            long count = 0;
            for(int p : piles) {
                count += (p + mid - 1) / mid;
            }
            if(count > h) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return l;
    }
};
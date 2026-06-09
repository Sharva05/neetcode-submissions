class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,l=0,r=prices.size()-1;
        while(l<r){
            profit= max(profit, prices[r]-prices[l]);
            if((prices[l]-prices[l+1]) > (prices[r-1]-prices[r]))
                l++;
            else r--;
        }
        return profit;
    }
};

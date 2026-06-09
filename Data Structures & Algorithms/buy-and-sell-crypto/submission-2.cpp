class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,min=0, maxi=1, len=prices.size();
        for(int i=1; i<len; i++){
            if(prices[min] > prices[i] && min!=len-1) min = i;
            if(prices[maxi] <= prices[i] && maxi!=0) maxi= i;
        }
        for(int i=0; i<maxi; i++){
            profit=max(profit, prices[maxi]-prices[i]);
        }
        for(int i=min+1; i<len; i++){
            profit=max(profit, prices[i]-prices[maxi]);
        }
        return profit;
    }
};

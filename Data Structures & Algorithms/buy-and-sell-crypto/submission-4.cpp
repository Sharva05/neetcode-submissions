class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,min=0, maxi=prices.size()-1, len=prices.size();
        for(int i=1; i<len; i++){
            if(prices[i] < prices[min] && i!=len-1) min = i;
            if(prices[i] >= prices[maxi] && i!=0) maxi= i;
        }
        if(maxi>min) return prices[maxi]-prices[min];
        for(int i=0; i<maxi; i++){
            profit=max(profit, prices[maxi]-prices[i]);
        }
        for(int i=min+1; i<len; i++){
            profit=max(profit, prices[i]-prices[min]);
        }
        return profit;
    }
};

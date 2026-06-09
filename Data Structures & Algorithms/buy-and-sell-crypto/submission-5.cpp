class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,min=0, maxi=-1, len=prices.size();
        for(int i=1; i<len; i++){
            if(i!=len-1 && prices[i] < prices[min]) min = i;
            if(i!=0 && prices[i] >= prices[maxi]) maxi= i;
        }
        for(int i=0; i<maxi; i++){
            profit=max(profit, prices[maxi]-prices[i]);
        }
        for(int i=min+1; i<len; i++){
            profit=max(profit, prices[i]-prices[min]);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX, profit=0;
        for(int n:prices){
            if(n>mini){
                profit=max(profit, n-mini);
            }
            else {
                mini=n;
            }
        }
        return profit;
    }
};

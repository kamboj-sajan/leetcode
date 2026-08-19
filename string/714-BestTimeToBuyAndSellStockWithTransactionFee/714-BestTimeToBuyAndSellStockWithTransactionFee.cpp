// Last updated: 19/08/2026, 15:58:05
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        long aheadNotbuy,aheadbuy,curNotbuy,curbuy;
        aheadNotbuy = aheadbuy = 0;
        for(int i=n-1; i>=0; i--){
                long profit = 0;
                
                curbuy = max(-prices[i]+aheadNotbuy,0+aheadbuy);
                
                    curNotbuy = max(prices[i]+aheadbuy - fee,0+aheadNotbuy);
            aheadbuy = curbuy;
            aheadNotbuy = curNotbuy;
        }
        return aheadbuy;
    }
};
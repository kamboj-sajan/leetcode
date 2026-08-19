// Last updated: 19/08/2026, 16:05:48
/*
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
        vector<vector<int>> after(2,vector<int> (k+1,0));
        vector<vector<int>> cur(2,vector<int> (k+1,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy == 1){
                        cur[buy][cap] = max(-prices[ind]+after[0][cap],after[1][cap]);
                    }else{
                        cur[buy][cap] = max(prices[ind]+after[1][cap-1],0 + after[0][cap]);
                    }
                }
            }
            after = cur;
        }
        return after[1][k];
    }
};
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       vector<int> after(2*k+1,0);
       vector<int> cur(2*k+1,0);
       int n = prices.size();
       for(int ind=n-1; ind>=0; ind--){
        for(int tranNo=2*k-1; tranNo>=0; tranNo--){
            if(tranNo % 2 == 0){
                cur[tranNo] = max(-prices[ind]+after[tranNo+1],after[tranNo]);
            }
            else{
                cur[tranNo] = max(prices[ind]+after[tranNo + 1],after[tranNo]);
            }
        }
        after = cur;
       }
       return after[0];
    }
};
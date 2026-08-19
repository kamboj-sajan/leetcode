// Last updated: 19/08/2026, 16:03:07
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind=n-1; ind>=0; ind--){
            dp[ind][1] = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            dp[ind][0] = max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
        }
        return dp[0][1];
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> cur(2,0);
        for(int ind=n-1; ind>=0; ind--){
            cur[1] = max(-prices[ind]+front1[0],front1[1]);
            cur[0] = max(prices[ind]+front2[1],front1[0]);
            front2 = front1;
            front1 = cur;
        }
        return cur[1];
    }
};
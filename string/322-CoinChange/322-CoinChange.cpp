// Last updated: 19/08/2026, 16:03:01
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<int> prev(amount+1,0),cur(amount+1);
       for(int T=0; T<=amount; T++){
        if(T % coins[0] == 0)prev[T] = T/coins[0];
        else prev[T] = INT_MAX;
       } 
       for(int i=1; i<n; i++){
        for(int t=0; t<=amount; t++){
            int notTake = prev[t];
            int take = 1e9;
            if(coins[i] <= t)take = 1 + cur[t-coins[i]];
            cur[t] = min(take,notTake);
        }
        prev = cur;
       }
       int ans = prev[amount];
       if(ans >= 1e9)return -1;
       return ans;
    }
};
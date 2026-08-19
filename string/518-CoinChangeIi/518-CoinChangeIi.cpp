// Last updated: 19/08/2026, 16:00:34
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
     vector<int> prev(amount+1,0),cur(amount+1,0);
     for(int T=0; T<=amount; T++)prev[T] = (T % coins[0] == 0);
     for(int i=1; i<n; i++){
        for(int T=0; T<=amount; T++){
            long notTake = prev[T];
            long take = 0;
            if(coins[i] <= T)take = cur[T-coins[i]];
            cur[T] = take + notTake;
        }
        prev = cur;
     }
     return prev[amount];
    }
};
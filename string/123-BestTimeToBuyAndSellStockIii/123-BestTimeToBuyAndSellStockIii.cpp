// Last updated: 19/08/2026, 16:08:09
// class Solution {
// public:
//     int f(int ind,int buy,int n,vector<int>& a ,int cnt){
//         long profit = 0;
//         if(cnt >= 2){
//             return 0;
//         }
//        if(ind == n){
//         return 0;
//        }
//        if(buy){
//         profit = max(-a[ind]+f(ind+1,0,n,a,cnt),f(ind+1,1,n,a,cnt));
//        }
//        else{
//         profit = max(a[ind]+f(ind+1,1,n,a,cnt+1),f(ind+1,0,n,a,cnt));
//        }
//        return profit;

//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int cnt = 0;
//         return f(0,1,n,prices,cnt);
//     }
// };

class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2,vector<int> (3,0));
        vector<vector<int>> cur(2,vector<int> (3,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy == 1){
                        cur[buy][cap] = max(-prices[ind]+after[0][cap],after[1][cap]);
                    }else{
                        cur[buy][cap] = max(prices[ind]+after[1][cap-1],0 + after[0][cap]);
                    }
                }
            }
            after = cur;
        }
        return after[1][2];
    }
};
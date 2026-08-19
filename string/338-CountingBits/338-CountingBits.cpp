// Last updated: 19/08/2026, 16:02:51
// class Solution {
// public:
//     int f(int n,vector<int> &dp){
//         if(n == 0){
//             return 0;
//         }
//         int ans = 0;
//         ans = ans + (n%2) + f(n/2,dp);
//         return dp[n] = ans;
//     }
// public:
//     vector<int> countBits(int n) {
//         vector<int> dp(n+1,-1);
//         for(int i=1; i<=n; ++i){
//             f(i,dp);
//         }
//         dp[0] = 0;
//         return dp;
//     }
// };

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> dp(n+1,0);
//         for(int i=1; i<=n; ++i){
//            dp[i] = dp[i/2] + i%2;
//         }
//         return dp;
//     }
// };

class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            ret[i] = ret[i >> 1] + (i & 1);
        }
        return ret;
    }
};
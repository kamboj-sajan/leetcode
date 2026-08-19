// Last updated: 19/08/2026, 16:02:47
// class Solution {
// public:
//     int f(int i,vector<int> &dp){
//         if(i <= 1)return 1;
//         if(dp[i] != -1)return dp[i];
//         int ans = 1;
//         for(int j=1; j<i; ++j){
//             ans = max(ans,max(j*(i-j),j*f(i-j,dp)));
//         }
//         return dp[i] = ans;
//     } 
// public:
//     int integerBreak(int n) {
//         vector<int> dp(n+1,-1);
//         f(n,dp);
//         return dp[n];
//     }
// };

// class Solution {
// public:
//     int integerBreak(int n) {
//         if (n == 2) return 1;
//         if (n == 3) return 2;
//         int ans = 1;
//         while (n > 4) {
//             ans *= 3;
//             n -= 3;
//         }
//         return ans * n;
//     }
// };

class Solution {
public:
    int integerBreak(int n){
        if(n==2)return 1;
        if(n==3) return 2;
        int p=1;
        while(n>4){
            p*=3;
            n-=3;
        }
        p*=n;
        return p;
        
    }
};
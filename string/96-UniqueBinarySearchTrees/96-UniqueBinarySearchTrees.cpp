// Last updated: 19/08/2026, 16:09:34
// class Solution {
// public:
//     int f(int n,vector<int>&dp){
//         if(n <=1){
//             return 1;
//         }
//         if(dp[n] != -1)return dp[n];
//         int ans = 0;
//         for(int i=1; i<=n; ++i){
//         int a = f(i-1,dp);
//         int b = f(n-i,dp);
//         ans += a*b;
//         }
//         return dp[n] = ans;
//     }
// public:
//     int numTrees(int n) {
//         if(n <= 1)return 1;
//         vector<int> dp(n+1,-1);
//         return f(n,dp);
//     }
// };

// class Solution {
// public:
//     int numTrees(int n) {
//         if(n <= 1)return 1;
//         int ans = 0;
//         for(int i=1; i<=n; ++i){
//             ans += numTrees(i-1)*numTrees(n-i);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int numTrees(int n) {
//         vector<int>dp(n+1,0);
//         dp[1]=1;
//           dp[0]=1;
//         for(int i=2;i<n+1;i++){
//             for(int j=1;j<=i;j++){
//                 dp[i]+=dp[j-1]*dp[i-j];
//             }
//         }
//         return dp[n];
//     }
// };

// class Solution {
// public:
//     int f(int n, vector<int>& dp) {
//         if (n <= 1) return 1;
//         if (dp[n] != -1) return dp[n];
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             int left = f(i - 1, dp);
//             int right = f(n - i, dp);

//             ans += left * right;
//         }
//         return dp[n] = ans;
//     }

//     int numTrees(int n) {
//         vector<int> dp(n + 1, -1);
//         return f(n, dp);
//     }
// };

// class Solution {
// public:
//     int numTrees(int n) {
//         vector<int> dp(n + 1, 0);
//         dp[0] = 1;
//         dp[1] = 1;
//         for (int nodes = 2; nodes <= n; nodes++) {
//             for (int root = 1; root <= nodes; root++) {
//                 dp[nodes] += dp[root - 1] * dp[nodes - root];
//             }
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int numTrees(int n) {
        long long catalan = 1;

        for (int i = 0; i < n; i++) {
            catalan = catalan * 2 * (2 * i + 1) / (i + 2);
        }

        return (int)catalan;
    }
};
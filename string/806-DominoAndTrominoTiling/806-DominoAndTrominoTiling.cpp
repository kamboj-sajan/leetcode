// Last updated: 19/08/2026, 15:56:44
// class Solution {
// public:
//     int mod = 1e9+7;
//     int f(int i,vector<int> &dp){
//         if(i == 0)return 1;
//         if(i == 1)return 1;
//         if(i == 2)return 2;
//         if(dp[i] != -1)return dp[i];
//         int j = (2*f(i-1,dp)%mod + f(i-3,dp)%mod)%mod;
//         return dp[i] = j;
//     }
// public:
//     int numTilings(int n) {
//         vector<int> dp(n+1,-1);
//         return f(n,dp);
//     }
// };

// class Solution {
// public:
//     int numTilings(int n) {
//          constexpr int kMod = 1'000'000'007;
//     vector<long> dp(1001);
//     dp[1] = 1;
//     dp[2] = 2;
//     dp[3] = 5;

//     for (int i = 4; i <= n; ++i)
//       dp[i] = (2 * dp[i - 1] + dp[i - 3]) % kMod;

//     return dp[n];
//     }
// };

class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9 + 7;

        if (n == 1) return 1;
        if (n == 2) return 2;

        long long a = 1; // dp[0]
        long long b = 1; // dp[1]
        long long c = 2; // dp[2]

        for (int i = 3; i <= n; i++) {
            long long d = (2 * c + a) % mod;
            a = b;
            b = c;
            c = d;
        }

        return c;
    }
};
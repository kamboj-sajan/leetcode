// Last updated: 19/08/2026, 15:55:16
// class Solution {
// public:
//     unordered_set<string> st;
//     void f(int n,unordered_map<int, vector<int>> &mpp,int d,string temp){
//         if(n == 0){
//             st.insert(temp);
//             return;
//         }
//         for(int nxt : mpp[d]) {
//         temp.push_back(nxt + '0');
//         f(n-1, mpp, nxt, temp);
//         temp.pop_back();
//         }
//         return;
//     }
// public:
//     int knightDialer(int n) {
//       unordered_map<int, vector<int>> mpp;
//       mpp[0] = {4,6};
//       mpp[1] = {6,8};
//       mpp[2] = {7,9};
//       mpp[3] = {4,8};
//       mpp[4] = {0,3,9};
//       mpp[6] = {0,1,7}; 
//       mpp[7] = {6,2};
//       mpp[8] = {1,3};
//       mpp[9] = {2,4};
//       if(n == 1)return 10;
//       for(int i=0; i<=9; ++i){
//         if(i ==5)continue;
//         f(n-1,mpp,i,string(1,i + '0'));
//       }
//       return st.size();
//     }
// };


// class Solution {
// public:
//     const int mod = 1e9 + 7;
//     int f(int n,unordered_map<int, vector<int>> &mpp,int d,vector<vector<int>> &dp){
//         if(n == 0){
//             return 1;
//         }
//         if(dp[n][d] != -1)return dp[n][d];
//         long long ans = 0;
//         for(int nxt : mpp[d]) {
//         ans = (ans + f(n-1, mpp, nxt,dp))%mod;
//         }
//         return dp[n][d] = ans;
//     }
// public:
//     int knightDialer(int n) {
//       unordered_map<int, vector<int>> mpp;
//       mpp[0] = {4,6};
//       mpp[1] = {6,8};
//       mpp[2] = {7,9};
//       mpp[3] = {4,8};
//       mpp[4] = {0,3,9};
//       mpp[6] = {0,1,7}; 
//       mpp[7] = {6,2};
//       mpp[8] = {1,3};
//       mpp[9] = {2,4};
//       vector<vector<int>> dp(n+1,vector<int> (10,-1));
//       long long ans = 0;
//       if(n == 1)return 10;
//       for(int i=0; i<=9; ++i){
//         if(i ==5)continue;
//         ans = (ans + f(n-1,mpp,i,dp))%mod;
//       }
//       return ans;
//     }
// };

// class Solution {
// public:
//     const int MOD = 1e9 + 7;

//     int solve(int digit,
//               int rem,
//               vector<vector<int>>& dp,
//               vector<vector<int>>& moves) {

//         if (rem == 0) return 1;

//         if (dp[digit][rem] != -1)
//             return dp[digit][rem];

//         long long ans = 0;

//         for (int nxt : moves[digit]) {
//             ans = (ans + solve(nxt, rem - 1, dp, moves)) % MOD;
//         }

//         return dp[digit][rem] = ans;
//     }

//     int knightDialer(int n) {
//         vector<vector<int>> moves = {
//             {4,6},      // 0
//             {6,8},      // 1
//             {7,9},      // 2
//             {4,8},      // 3
//             {0,3,9},    // 4
//             {},         // 5
//             {0,1,7},    // 6
//             {2,6},      // 7
//             {1,3},      // 8
//             {2,4}       // 9
//         };
//         vector<vector<int>> dp(10,
//                                vector<int>(n, -1));
//         long long ans = 0;
//         for (int digit = 0; digit <= 9; digit++) {
//             ans = (ans + solve(digit, n - 1, dp, moves)) % MOD;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int knightDialer(int n) {
//         const int MOD = 1e9 + 7;

//         vector<vector<int>> moves = {
//             {4, 6},      // 0
//             {6, 8},      // 1
//             {7, 9},      // 2
//             {4, 8},      // 3
//             {0, 3, 9},   // 4
//             {},          // 5
//             {0, 1, 7},   // 6
//             {2, 6},      // 7
//             {1, 3},      // 8
//             {2, 4}       // 9
//         };

//         vector<vector<long long>> dp(n, vector<long long>(10, 0));

//         // Base case
//         for (int digit = 0; digit < 10; digit++) {
//             dp[0][digit] = 1;
//         }

//         for (int rem = 1; rem < n; rem++) {
//             for (int digit = 0; digit < 10; digit++) {

//                 long long ways = 0;

//                 for (int nxt : moves[digit]) {
//                     ways = (ways + dp[rem - 1][nxt]) % MOD;
//                 }

//                 dp[rem][digit] = ways;
//             }
//         }
//         long long ans = 0;
//         for (int digit = 0; digit < 10; digit++) {
//             ans = (ans + dp[n - 1][digit]) % MOD;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int knightDialer(int n) {
//         if (n == 1)
//             return 10;
//         const long long MOD = 1e9 + 7;
//         // a, b, c, d groups
//         long long a = 4;
//         long long b = 2;
//         long long c = 2;
//         long long d = 1;
//         for (int i = 1; i < n; i++) {
//             long long newA = (2 * b + 2 * c) % MOD;
//             long long newB = (a + 2 * d) % MOD;
//             long long newC = a % MOD;
//             long long newD = b % MOD;
//             a = newA;
//             b = newB;
//             c = newC;
//             d = newD;
//         }
//         return (a + b + c + d) % MOD;
//     }
// };

class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> moves = {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {0,3,9},
            {},
            {0,1,7},
            {2,6},
            {1,3},
            {2,4}
        };

        vector<long long> prev(10, 1), curr(10);

        for (int rem = 1; rem < n; rem++) {

            fill(curr.begin(), curr.end(), 0);

            for (int digit = 0; digit < 10; digit++) {

                for (int nxt : moves[digit]) {
                    curr[digit] =
                        (curr[digit] + prev[nxt]) % MOD;
                }
            }

            prev = curr;
        }

        long long ans = 0;

        for (int digit = 0; digit < 10; digit++) {
            ans = (ans + prev[digit]) % MOD;
        }

        return ans;
    }
};
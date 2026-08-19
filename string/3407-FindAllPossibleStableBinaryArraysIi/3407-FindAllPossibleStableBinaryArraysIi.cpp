// Last updated: 19/08/2026, 15:28:07
// class Solution {
// public:
//     int numberOfStableArrays(int zero, int one, int limit) {
//         const int MOD = 1e9 + 7;
//         vector<vector<array<long,2>>> dp(
//             zero+1, vector<array<long,2>>(one+1, {0LL,0LL}));

//         for (int i = 1; i <= min(zero,limit); i++) dp[i][0][0] = 1;
//         for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;

//         for (int i = 1; i <= zero; i++) {
//             for (int j = 1; j <= one; j++) {
//                 long over0 = (i-limit >= 1) ? dp[i-limit-1][j][1] : 0;
//                 long over1 = (j-limit >= 1) ? dp[i][j-limit-1][0] : 0;
//                 dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] - over0 + MOD) % MOD;
//                 dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1] - over1 + MOD) % MOD;
//             }
//         }
//         return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
//     }
// };


//tle
// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int arr[1001][1001][2];
// public:
//     int numberOfStableArrays(int zero, int one, int limit) {
//         memset(arr,0,sizeof(arr));
//         arr[0][0][1] = 1;
//         arr[0][0][0] = 1;
//         for(int onesleft = 0; onesleft <= one; onesleft++){
//             for(int zerosleft = 0; zerosleft <= zero; zerosleft++){
//                 if(onesleft == 0 && zerosleft == 0){
//                     continue;
//                 }
//                 int result = 0;
//                 for(int len = 1; len <= min(zerosleft,limit); len++){
//                     result  = (result + arr[onesleft][zerosleft-len][0])%mod;
//                 }
//                 arr[onesleft][zerosleft][1] = result;
//                 result = 0;
//                 for(int len = 1; len <= min(onesleft,limit); len++){
//                     result = (result + arr[onesleft-len][zerosleft][1])%mod;
//                 }
//                 arr[onesleft][zerosleft][0] = result;
//             }
//         }
//         int startWithOnes = arr[one][zero][false];
//         int startWithZeros = arr[one][zero][true];
//         return (startWithOnes + startWithZeros) % mod;
//     }
// };

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
            int mod = 1e9 + 7;
            vector<vector<vector<int>>> arr(zero+1,vector<vector<int>>(one+1,vector<int>(2,0)));
            for(int i=0; i<=min(zero,limit); i++)arr[i][0][0] = 1;
            for(int j=0; j<=min(one,limit); j++)arr[0][j][1] = 1;
            for(int i=0; i<= zero; i++){
                for(int j=0; j<=one; j++){
                    if(i == 0 || j == 0)continue;
                    arr[i][j][1] = (arr[i][j-1][1] + arr[i][j-1][0]) % mod;
                    if(j-1 >= limit){
                        arr[i][j][1] = (arr[i][j][1] - arr[i][j-1-limit][0] + mod) % mod; 
                    }
                    arr[i][j][0] = (arr[i-1][j][0] + arr[i-1][j][1]) % mod;
                    if(i-1 >= limit){
                        arr[i][j][0] = (arr[i][j][0] - arr[i-1-limit][j][1] + mod) % mod;
                    }
                }
            }
        return (arr[zero][one][0] + arr[zero][one][1]) % mod;    
    }
};






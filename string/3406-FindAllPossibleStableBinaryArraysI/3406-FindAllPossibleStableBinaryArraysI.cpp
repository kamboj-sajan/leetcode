// Last updated: 19/08/2026, 15:28:09
// #define MOD 1000000007
// class Solution {
// public:
//     int numberOfStableArrays(int zero, int one, int limit) {
//         vector<vector<array<int, 2>>> dp(zero + 1, vector<array<int, 2>>(one + 1, {0, 0}));
//         for (int i = 1; i <= min(zero, limit); i++) dp[i][0][0] = 1;
//         for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;
//         for (int i = 1; i <= zero; i++) {
//             for (int j = 1; j <= one; j++) {
//                 long long val0 = (0LL + dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
//                 if (i > limit) val0 = (val0 - dp[i - limit - 1][j][1] + MOD) % MOD;
//                 dp[i][j][0] = val0;
//                 long long val1 = (0LL + dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
//                 if (j > limit) val1 = (val1 - dp[i][j - limit - 1][0] + MOD) % MOD;
//                 dp[i][j][1] = val1;
//             }
//         }
//         return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
//     }
// };

// #define mod 1000000007
// class Solution {
// public:
//     int f(int onesleft,int zerosleft,bool lastwasone,int limit){
//         if(onesleft == 0 && zerosleft == 0){
//             return 1;
//         }
//         int result = 0;
//         if(lastwasone){
//             for(int len = 1; len <= min(zerosleft,limit); len++){
//                 result += (f(onesleft,zerosleft-len,false,limit)%mod);
//             }
//         }else{
//             for(int len = 1; len <= min(onesleft,limit); len++){
//                 result += (f(onesleft-len,zerosleft,true,limit)%mod);
//             }
//         }
//         return result;
//     }
// public:
//     int numberOfStableArrays(int zero, int one, int limit) {
//         int startWithOnes = f(one,zero,false,limit);
//         int startWithZeros = f(one,zero,true,limit);
//         return (startWithOnes + startWithZeros) % mod;
//     }
// };




// tc = O(ones * zeros * 2 * min(ones,limit)) == O(ones * zeros * limit);
// sc = O(ones * zeros * 2) == O(ones * zeros);
// class Solution {
// public:
//     int mod = 1e9 + 7;
//     int arr[201][201][2];
//     int f(int onesleft,int zerosleft,bool lastwasone,int limit){
//         if(onesleft == 0 && zerosleft == 0){
//             return 1;
//         }
//         if(arr[onesleft][zerosleft][lastwasone] != -1){
//             return arr[onesleft][zerosleft][lastwasone];
//         }
//         int result = 0;
//         if(lastwasone){
//             for(int len = 1; len <= min(zerosleft,limit); len++){
//                 result = (result + f(onesleft,zerosleft-len,false,limit))%mod;
//             }
//         }else{
//             for(int len = 1; len <= min(onesleft,limit); len++){
//                 result = (result + f(onesleft-len,zerosleft,true,limit))%mod;
//             }
//         }
//         return arr[onesleft][zerosleft][lastwasone] = result;
//     }
// public:
//     int numberOfStableArrays(int zero, int one, int limit) {
//         memset(arr,-1,sizeof(arr));
//         int startWithOnes = f(one,zero,false,limit);
//         int startWithZeros = f(one,zero,true,limit);
//         return (startWithOnes + startWithZeros) % mod;
//     }
// };

class Solution {
public:
    int mod = 1e9 + 7;
    int arr[201][201][2];
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(arr,0,sizeof(arr));
        arr[0][0][1] = 1;
        arr[0][0][0] = 1;
        for(int onesleft = 0; onesleft <= one; onesleft++){
            for(int zerosleft = 0; zerosleft <= zero; zerosleft++){
                if(onesleft == 0 && zerosleft == 0){
                    continue;
                }
                int result = 0;
                for(int len = 1; len <= min(zerosleft,limit); len++){
                    result  = (result + arr[onesleft][zerosleft-len][0])%mod;
                }
                arr[onesleft][zerosleft][1] = result;
                result = 0;
                for(int len = 1; len <= min(onesleft,limit); len++){
                    result = (result + arr[onesleft-len][zerosleft][1])%mod;
                }
                arr[onesleft][zerosleft][0] = result;
            }
        }
        int startWithOnes = arr[one][zero][false];
        int startWithZeros = arr[one][zero][true];
        return (startWithOnes + startWithZeros) % mod;
    }
};




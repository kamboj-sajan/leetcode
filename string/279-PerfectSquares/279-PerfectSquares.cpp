// Last updated: 19/08/2026, 16:03:26
// class Solution {
// public:
//     vector<int> dp;
//     int f(int n){
//         if(n == 0)return 0;
//         int mini = INT_MAX;
//         if(n < 0)return INT_MAX;
//         for(int i=1; i*i <= n; ++i){
//             int c = 1 + f(n-i*i);
//             mini = min(mini,c);
//         }
//         return dp[n] = mini;
//     }
// public:
//     int numSquares(int n) {
//         dp.assign(n+1,-1);
//         int c = f(n);
//         return c;
//     }
// };

// class Solution {
// public:
//     vector<int> dp;
//     int f(int n){
//         if(n == 0) return 0;
//         if(dp[n] != -1) return dp[n];
//         int mini = INT_MAX;
//         for(int i = 1; i*i <= n; ++i){
//             int sub = f(n - i*i);
//             if(sub != INT_MAX){
//                 mini = min(mini, 1 + sub);
//             }
//         }
//         return dp[n] = mini;
//     }
//     int numSquares(int n) {
//         dp.assign(n+1, -1);
//         return f(n);
//     }
// };


// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> dp(n+1,INT_MAX);
//         dp[0] = 0;
//         for(int i=1; i<=n; ++i){
//             for(int j=1; j*j<=i; ++j){
//                 dp[i] = min(dp[i],1+dp[i-j*j]);
//             }
//         }
//         return dp[n];
//     }
// };


// class Solution {
// public:
//     int numSquares(int n) {
//         int a = sqrt(n);
//         if(a*a == n)return 1;
//         while(n%4 == 0)n/=4;
//         if(n%8 == 7)return 4;
//         for(int i=1; i*i <=n; ++i){
//             int c = i*i;
//             int d = sqrt(n - c);
//             if(d*d == n-c)return 2;
//         }
//         return 3;
//     }
// };

// class Solution {
// public:
//     bool isPerfectSquare(int x){
//         int s = sqrt(x);
//         return s*s == x;
//     }
//     int numSquares(int n) {
//         // Step 1: Check 1
//         if(isPerfectSquare(n)) return 1;
//         // Step 2: Reduce n by removing factors of 4
//         while(n % 4 == 0) n /= 4;
//         // Check Legendre condition
//         if(n % 8 == 7) return 4;
//         // Step 3: Check 2
//         for(int i = 1; i*i <= n; i++){
//             if(isPerfectSquare(n - i*i)) return 2;
//         }
//         // Step 4: Otherwise
//         return 3;
//     }
// };


class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> vis(n+1,false);
        q.push(n);
        vis[n] = true;
        int lvl = 0;
        while(!q.empty()){
            int siz = q.size();
            lvl++;
            while(siz--){
                int cur = q.front();
            q.pop();
            for(int i=1; i*i<=cur; ++i){
                int nxt = cur - i*i;
                if(nxt == 0)return lvl;
                if(!vis[nxt]){
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
     }
        return lvl;
    }
};
// Last updated: 19/08/2026, 15:29:51
// class Solution {
// public:
//     using ll = long long;
//     vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         const ll mod = 12345;
//         vector<int> pre(n*m,1);
//         vector<int> suf(n*m);
//         ll p = 1;
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(i == 0 && j == 0)continue;
//                 if(j == 0)pre[i*m + j] = (p * grid[i-1][m-1])%mod;
//                 pre[i*m + j] = (p * grid[i][j-1]) % mod;
//             }
//         }
//         p = 1;
//         for(int i=n-1; i>=0; i--){
//             for(int j=m-1; j>=0; j--){
//                 if(i == n-1 && j == m-1)continue;
//                 if(j == m-1)suf[i*n + j] = (p * grid[i+1][0])%mod;
//                 suf[i*m + j] = (p * grid[i][j+1])%mod;
//             }
//         }
//         vector<vector<int>> ans(n,vector<int> (m,1));
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; ++j){
//                 ans[i][j] = (pre[i*m + j] * suf[i*m + j])%mod;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     using ll = long long;
//     vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int total = n * m;
//         const ll mod = 12345;
//         vector<ll> flat(total);
//         // 🔹 Flatten matrix
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 flat[i * m + j] = grid[i][j] % mod;
//             }
//         }
//         // 🔹 Prefix
//         vector<ll> pre(total, 1);
//         for(int i = 1; i < total; i++){
//             pre[i] = (pre[i-1] * flat[i-1]) % mod;
//         }
//         // 🔹 Suffix
//         vector<ll> suf(total, 1);
//         for(int i = total - 2; i >= 0; i--){
//             suf[i] = (suf[i+1] * flat[i+1]) % mod;
//         }
//         // 🔹 Build answer
//         vector<vector<int>> ans(n, vector<int>(m));

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 int idx = i * m + j;
//                 ans[i][j] = (pre[idx] * suf[idx]) % mod;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    static vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int N=12345, n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        uint64_t pref=1, suf=1;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                ans[i][j]=pref;
                pref=pref*grid[i][j]%N;
            }
        for(int i=n-1; i>=0; i--)
            for(int j=m-1; j>=0; j--){
                ans[i][j]=ans[i][j]*suf%N;
                suf=suf*grid[i][j]%N;
            }
        return ans;
    }
};

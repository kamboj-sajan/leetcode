// Last updated: 19/08/2026, 15:38:41
// class Solution {
// public:
//     using ll = long long;
//     ll maxi = INT_MIN;
//     void f(vector<vector<int>> &grid,ll res,int i,int j){
//         int m = grid.size();
//         int n = grid[0].size();
//         res *= grid[i][j];
//         if(i == m-1 && j == n-1){
//             if(res >= 0){
//                 maxi = max(maxi,res);
//             }
//             return;
//         }
//         if(i > m-1 || j > n-1)return;
//         if(j < n-1)f(grid,res,i,j+1);
//         if(i < m-1)f(grid,res,i+1,j);
//         return;
//     }
// public:
//     int maxProductPath(vector<vector<int>>& grid) {
//         f(grid,1,0,0);
//         if(maxi < 0)maxi = -1;
//         return maxi;
//     }
// };


class Solution {
public:
    using ll = long long;
    ll maxi = LLONG_MIN;
    int mod = 1e9 + 7;

    // store {maxProduct, minProduct}
    vector<vector<pair<ll,ll>>> dp;
    vector<vector<bool>> vis;

    pair<ll,ll> f(vector<vector<int>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return {LLONG_MIN, LLONG_MAX};

        if(vis[i][j]) return dp[i][j];

        // base case
        if(i == m-1 && j == n-1){
            return dp[i][j] = {grid[i][j], grid[i][j]};
        }

        vis[i][j] = true;

        auto right = f(grid, i, j+1);
        auto down  = f(grid, i+1, j);

        ll val = grid[i][j];

        vector<ll> candidates;

        if(right.first != LLONG_MIN){
            candidates.push_back(val * right.first);
            candidates.push_back(val * right.second);
        }
        if(down.first != LLONG_MIN){
            candidates.push_back(val * down.first);
            candidates.push_back(val * down.second);
        }

        ll mx = LLONG_MIN, mn = LLONG_MAX;

        for(ll x : candidates){
            mx = max(mx, x);
            mn = min(mn, x);
        }

        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<pair<ll,ll>>(n));
        vis.assign(m, vector<bool>(n, false));
        auto res = f(grid, 0, 0);
        if(res.first < 0) return -1;
        return res.first % mod;
    }
};
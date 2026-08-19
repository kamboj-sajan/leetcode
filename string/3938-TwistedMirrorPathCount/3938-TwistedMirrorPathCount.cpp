// Last updated: 19/08/2026, 15:23:29
class Solution {
public:
    const int MOD = 1e9+7;
    int n, m;
    vector<vector<int>> g;
    vector<vector<int>> dp;

    int dfs(int i, int j) {
        if (i >= n || j >= m) return 0;
        if (i == n-1 && j == m-1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        long long ans = 0;

        int ni = i, nj = j+1;
        if (nj < m) {
            if (g[ni][nj] == 0) ans = (ans + dfs(ni, nj)) % MOD;
            else {
                int cur_i = ni + 1, cur_j = nj;
                int enter_dir = 1;
                while (true) {
                    if (cur_i >= n || cur_j >= m) break;
                    if (cur_i == n-1 && cur_j == m-1) { ans = (ans + 1) % MOD; break; }
                    if (g[cur_i][cur_j] == 0) { ans = (ans + dfs(cur_i, cur_j)) % MOD; break; }
                    if (enter_dir == 0) { cur_i++; enter_dir = 1; }
                    else { cur_j++; enter_dir = 0; }
                }
            }
        }

        ni = i+1; nj = j;
        if (ni < n) {
            if (g[ni][nj] == 0) ans = (ans + dfs(ni, nj)) % MOD;
            else {
                int cur_i = ni, cur_j = nj + 1;
                int enter_dir = 0;
                while (true) {
                    if (cur_i >= n || cur_j >= m) break;
                    if (cur_i == n-1 && cur_j == m-1) { ans = (ans + 1) % MOD; break; }
                    if (g[cur_i][cur_j] == 0) { ans = (ans + dfs(cur_i, cur_j)) % MOD; break; }
                    if (enter_dir == 0) { cur_i++; enter_dir = 1; }
                    else { cur_j++; enter_dir = 0; }
                }
            }
        }

        return dp[i][j] = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(); m = g[0].size();
        dp.assign(n, vector<int>(m, -1));
        return dfs(0,0);
    }
};

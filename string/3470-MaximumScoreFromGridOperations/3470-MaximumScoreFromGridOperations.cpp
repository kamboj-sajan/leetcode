// Last updated: 19/08/2026, 15:27:52
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        // If only one column, no horizontal neighbor exists
        if (n == 1) return 0;

        // prefix[col][r] = sum of grid[0..r-1][col]
        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                prefix[col][row + 1] = prefix[col][row] + grid[row][col];
            }
        }

        auto getSum = [&](int col, int l, int r) -> long long {
            // sum grid[l..r-1][col]
            if (r <= l) return 0;
            return prefix[col][r] - prefix[col][l];
        };

        const long long NEG = -(long long)4e18;

        // dp[a][b] :
        // left height = a
        // current height = b
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, NEG));

        // virtual left boundary = 0
        for (int h0 = 0; h0 <= n; h0++) {
            dp[0][h0] = 0;
        }

        // process columns 0 ... n-2
        for (int col = 0; col < n - 1; col++) {
            vector<vector<long long>> ndp(n + 1, vector<long long>(n + 1, NEG));

            // current column height = b
            for (int b = 0; b <= n; b++) {
                // prefix max over a
                vector<long long> pref(n + 1, NEG);

                for (int a = 0; a <= n; a++) {
                    if (a == 0) pref[a] = dp[a][b];
                    else pref[a] = max(pref[a - 1], dp[a][b]);
                }

                // suffix max of dp[a][b] + contribution when a > c
                vector<long long> suff(n + 2, NEG);

                for (int a = n; a >= 0; a--) {
                    long long val = dp[a][b];
                    if (val != NEG) {
                        val += getSum(col, b, a); // if a <= b => 0
                    }
                    suff[a] = max(suff[a + 1], val);
                }

                // choose next height c
                for (int c = 0; c <= n; c++) {
                    long long best = NEG;

                    // case 1: a <= c
                    if (pref[c] != NEG) {
                        best = max(best, pref[c] + getSum(col, b, c));
                    }

                    // case 2: a > c
                    if (c + 1 <= n) {
                        best = max(best, suff[c + 1]);
                    }

                    ndp[b][c] = max(ndp[b][c], best);
                }
            }

            dp = move(ndp);
        }

        // finalize last column (right boundary height = 0)
        long long ans = 0;

        for (int a = 0; a <= n; a++) {
            for (int b = 0; b <= n; b++) {
                if (dp[a][b] == NEG) continue;

                // last column uses right virtual boundary = 0
                long long add = getSum(n - 1, b, a);

                ans = max(ans, dp[a][b] + add);
            }
        }

        return ans;
    }
};
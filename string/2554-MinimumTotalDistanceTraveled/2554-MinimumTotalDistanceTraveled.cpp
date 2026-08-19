// Last updated: 19/08/2026, 15:31:14
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        // dp[i][j] = min cost to fix robots from i to end using factories from j to end
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));

        // base case: no robots left
        for (int j = 0; j <= m; j++) dp[n][j] = 0;

        for (int j = m - 1; j >= 0; j--) {
            int pos = factory[j][0];
            int limit = factory[j][1];

            for (int i = n; i >= 0; i--) {
                long long cost = 0;

                for (int k = 0; k <= limit && i + k <= n; k++) {
                    if (k > 0) {
                        cost += abs(robot[i + k - 1] - pos);
                    }

                    if (dp[i + k][j + 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], cost + dp[i + k][j + 1]);
                    }
                }
            }
        }

        return dp[0][0];
    }
};
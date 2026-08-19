// Last updated: 19/08/2026, 15:24:00
// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid, int k) {
//         int m = grid.size(), n = grid[0].size();
//         const long long INF = 1e18;

//         // group cells by value
//         map<int, vector<pair<int,int>>> cells;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 cells[grid[i][j]].push_back({i, j});
//             }
//         }

//         // dist[i][j][t] = min cost to reach (i,j) using t teleports
//         vector<vector<vector<long long>>> dist(
//             m, vector<vector<long long>>(n, vector<long long>(k + 1, INF))
//         );

//         priority_queue<
//             tuple<long long,int,int,int>,
//             vector<tuple<long long,int,int,int>>,
//             greater<>
//         > pq;

//         dist[0][0][0] = 0;
//         pq.push({0, 0, 0, 0}); // cost, i, j, teleports used

//         while (!pq.empty()) {
//             auto [cost, i, j, t] = pq.top();
//             pq.pop();

//             if (cost > dist[i][j][t]) continue;

//             // move down
//             if (i + 1 < m) {
//                 long long nc = cost + grid[i + 1][j];
//                 if (nc < dist[i + 1][j][t]) {
//                     dist[i + 1][j][t] = nc;
//                     pq.push({nc, i + 1, j, t});
//                 }
//             }

//             // move right
//             if (j + 1 < n) {
//                 long long nc = cost + grid[i][j + 1];
//                 if (nc < dist[i][j + 1][t]) {
//                     dist[i][j + 1][t] = nc;
//                     pq.push({nc, i, j + 1, t});
//                 }
//             }

//             // teleport
//             if (t < k) {
//                 int curVal = grid[i][j];
//                 for (auto& [val, vec] : cells) {
//                     if (val > curVal) break;
//                     for (auto& [x, y] : vec) {
//                         if (cost < dist[x][y][t + 1]) {
//                             dist[x][y][t + 1] = cost;
//                             pq.push({cost, x, y, t + 1});
//                         }
//                     }
//                 }
//             }
//         }

//         long long ans = INF;
//         for (int t = 0; t <= k; t++) {
//             ans = min(ans, dist[m - 1][n - 1][t]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    static constexpr int INF = 1000000000;
    int rows = 0, cols = 0, maxval = 0;

    void dp_iteration(vector<vector<int>>& dp, vector<int>& best_teleport, vector<vector<int>>& grid) {
        for (int r = rows - 1; r >= 0; --r) {
            for (int c = cols - 1; c >= 0; --c) {
                int walk = ((r != rows - 1) || (c != cols - 1)) ? INF : 0;
                if (r + 1 < rows) walk = min(walk, dp[r + 1][c] + grid[r + 1][c]);
                if (c + 1 < cols) walk = min(walk, dp[r][c + 1] + grid[r][c + 1]);
                dp[r][c] = min(walk, best_teleport[grid[r][c]]);
            }
        }
    }

    vector<int> build_teleport(vector<vector<int>>& dp, vector<vector<int>>& grid) {
        vector<int> teleport(maxval + 1, INF);

        // First build mincost for each v = value
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c) 
                teleport[grid[r][c]] = min(teleport[grid[r][c]], dp[r][c]);

        // Then build prefix mincost for v <= value
        for (int v = 0; v <= maxval; ++v)
            teleport[v] = min(teleport[v], v > 0 ? teleport[v - 1] : INF);

        return teleport;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        // Calculate dimensions
        rows = grid.size(), cols = grid[0].size();
        for (auto &row: grid) maxval = max(maxval, *max_element(row.begin(), row.end()));

        vector<int> best_teleport(maxval + 1, INF);
        vector<vector<int>> dp(rows, vector<int>(cols, INF));
        dp[rows - 1][cols - 1] = 0; // zero cost to reach dest from dest

        for (int t = 0; t <= k; ++t) { // t teleports allowed
            dp_iteration(dp, best_teleport, grid);
            best_teleport = build_teleport(dp, grid);
        }

        return dp[0][0];
    }
};
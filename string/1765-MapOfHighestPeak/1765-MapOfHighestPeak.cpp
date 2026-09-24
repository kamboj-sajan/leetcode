// Last updated: 25/09/2026, 01:10:05
// class Solution {
// public:
//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
//        int n = isWater.size();
//         int m = isWater[0].size();
//         vector<vector<int>> h(n, vector<int>(m, -1));
//         queue<pair<int,int>> q;
//         // Put ALL water cells into the queue
//         for(int r = 0; r < n; r++) {
//             for(int c = 0; c < m; c++) {
//                 if(isWater[r][c] == 1) {
//                     h[r][c] = 0;
//                     q.push({r, c});
//                 }
//             }
//         }
//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, 1, 0, -1};
//         while(!q.empty()) {
//             auto [r, c] = q.front();
//             q.pop();
//             for(int i = 0; i < 4; i++) {
//                 int nr = r + dr[i];
//                 int nc = c + dc[i];
//                 if(nr < 0 || nr >= n || nc < 0 || nc >= m)
//                     continue;
//                 // Not visited yet
//                 if(h[nr][nc] == -1) {
//                     h[nr][nc] = h[r][c] + 1;
//                     q.push({nr, nc});
//                 }
//             }
//         }
//         return h;
//     }
// };

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        int INF = 1e9; // Large value to represent unvisited land
        
        // initialize the matrix
        vector<vector<int>> res(m, vector<int>(n, INF));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0; // Water cells must be 0
                }
            }
        }
        
        // Step 2: Forward Pass (Check Top and Left neighbors)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][j] != 0) { // Only process land cells
                    if (i > 0) res[i][j] = min(res[i][j], 1 + res[i - 1][j]);
                    if (j > 0) res[i][j] = min(res[i][j], 1 + res[i][j - 1]);
                }
            }
        }
        
        // Step 3: Backward Pass (Check Bottom and Right neighbors)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[i][j] != 0) { // Only process land cells
                    if (i < m - 1) res[i][j] = min(res[i][j], 1 + res[i + 1][j]);
                    if (j < n - 1) res[i][j] = min(res[i][j], 1 + res[i][j + 1]);
                }
            }
        }
        
        return res;
    }
};
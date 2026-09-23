// Last updated: 24/09/2026, 00:48:53
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (m== 1 && n==1) {
            return grid[0][0];
        }
        vector<vector<vector<vector<int>>>> dist(m,
            vector<vector<vector<int>>>(n,
                vector<vector<int>>(4,vector<int>(k + 1, INT_MAX))));
        priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = dr[i];
            int nc = dc[i];
            if (nr>=0 && nr<m && nc >= 0 && nc<n) {
                int ct = grid[0][0] + grid[nr][nc];
                dist[nr][nc][i][0] = ct;
                pq.push({ct, nr, nc, i, 0});
            }
        }
        while (!pq.empty()) {
            auto a = pq.top();
            int ct = get<0>(a);
            int r = get<1>(a);
            int c = get<2>(a);
            int dir = get<3>(a);
            int turns = get<4>(a);
            pq.pop();
            if (ct != dist[r][c][dir][turns]) {
                continue;
            }
            if (r == m-1 && c == n-1) {
                return ct;
            }
            for (int nd = 0; nd < 4; nd++) {
                int nr = r + dr[nd];
                int nc = c + dc[nd];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }
                int nt = turns;
                if (nd != dir) {
                    nt++;
                }
                if (nt > k) {
                    continue;
                }
                int nct = ct + grid[nr][nc];
                if (nct < dist[nr][nc][nd][nt]) {
                    dist[nr][nc][nd][nt] = nct;
                    pq.push({nct, nr, nc, nd, nt});
                }
            }
        }
        return -1;
    }
};
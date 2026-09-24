// Last updated: 25/09/2026, 01:05:35
// // // class Solution {
// // // public:
// // //     int minimumObstacles(vector<vector<int>>& grid) {
// // //         int n = grid.size();
// // //         int m = grid[0].size();
// // //         priority_queue<
// // //         pair<int,pair<int,int>>,
// // //         vector<pair<int,pair<int,int>>>,
// // //         greater<pair<int,pair<int,int>>>
// // //         > pq;
// // //         vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
// // //         dis[0][0] = 0;
// // //         pq.push({0,{0,0}});
// // //         int drc[] = {0,-1,0,1,0};
// // //         while(!pq.empty()){
// // //             auto [obs,dir] = pq.top();
// // //             pq.pop();
// // //             int r = dir.first;
// // //             int c = dir.second;
// // //             if(obs > dis[r][c])continue;
// // //             if(r == n-1 && c == m-1)return obs;
// // //             for(int i=0; i<4; i++){
// // //                 int nr = r + drc[i];
// // //                 int nc = c + drc[i+1];
// // //                 if(nr >= 0 && nr < n && nc >= 0 && nc < m){
// // //                     int newobs = obs + grid[nr][nc];
// // //                     if(newobs < dis[nr][nc]){
// // //                         dis[nr][nc] = newobs;
// // //                         pq.push({newobs,{nr,nc}});
// // //                     }
// // //                 }
// // //             }
// // //         }
// // //         return -1;
// // //     }
// // // };

// // class Solution {
// // public:
// //     int minimumObstacles(vector<vector<int>>& grid) {
// //         int m = grid.size();
// //         int n = grid[0].size();
// //         deque<int> dq;
// //         vector<int> dist(m * n, 1e9);
// //         dist[0] = 0;
// //         vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// //         dq.push_front(0);

// //         while (!dq.empty()) {
// //             int node = dq.front();
// //             dq.pop_front();

// //             int r = node / n;
// //             int c = node - r * n;

// //             for (auto it : dirs) {
// //                 int nr = r + it.first;
// //                 int nc = c + it.second;

// //                 int newNode = nr * n + nc;

// //                 int w = 0;

// //                 if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
// //                     if (grid[nr][nc] == 1)
// //                         w = 1;

// //                     if (dist[newNode] > dist[node] + w) {
// //                         dist[newNode] = dist[node] + w;

// //                         if (w == 0)
// //                             dq.push_front(newNode);

// //                         else
// //                             dq.push_back(newNode);
// //                     }
// //                 }
// //             }
// //         }

// //         return dist[m * n - 1] == 1e9 ? 0 : dist[m * n - 1];
// //     }
// // };

// class Solution {
// public:
//     int minimumObstacles(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         // dist[i][j] = minimum obstacles removed to reach (i,j)
//         vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

//         priority_queue<
//             pair<int, pair<int, int>>,
//             vector<pair<int, pair<int, int>>>,
//             greater<pair<int, pair<int, int>>>
//         > pq;

//         dist[0][0] = 0;
//         pq.push({0, {0, 0}});

//         int dr[] = {-1, 1, 0, 0};
//         int dc[] = {0, 0, -1, 1};

//         while (!pq.empty()) {
//             auto [cost, pos] = pq.top();
//             pq.pop();

//             int r = pos.first;
//             int c = pos.second;

//             // Ignore outdated entry
//             if (cost > dist[r][c])
//                 continue;

//             // Destination reached
//             if (r == m - 1 && c == n - 1)
//                 return cost;

//             for (int k = 0; k < 4; k++) {
//                 int nr = r + dr[k];
//                 int nc = c + dc[k];

//                 if (nr < 0 || nr >= m || nc < 0 || nc >= n)
//                     continue;

//                 int newCost = cost + grid[nr][nc];

//                 if (newCost < dist[nr][nc]) {
//                     dist[nr][nc] = newCost;
//                     pq.push({newCost, {nr, nc}});
//                 }
//             }
//         }

//         return dist[m - 1][n - 1];
//     }
// };

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(
            m, vector<int>(n, INT_MAX)
        );

        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                int newCost = dist[r][c] + grid[nr][nc];

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;

                    if (grid[nr][nc] == 0)
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
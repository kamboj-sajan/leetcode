// Last updated: 25/09/2026, 01:14:22
// // class Solution {
// // public:
// //     int shortestPath(vector<vector<int>>& grid, int k) {
// //         int n = grid.size();
// //         int m = grid[0].size();
// //         queue<tuple<int,int,int,int>> pq;
// //         pq.push({0,0,0,k});
// //         int dr[] = {-1,0,1,0};
// //         int dc[] = {0,1,0,-1};
// //         vector<vector<int>> vis(n,vector<int> (m,-1));
// //         vis[0][0] = k;
// //         while(!pq.empty()){
// //             int sz = pq.size();
// //             while(sz--){
// //                 auto p = pq.front();
// //                 int steps = get<0>(p);
// //                 int r = get<1>(p);
// //                 int c = get<2>(p);
// //                 if(r == n-1 && c == m-1)return steps;
// //                 int obs = get<3>(p);
// //                 pq.pop();
// //                 for(int i=0; i<4; i++){
// //                     int nr = r + dr[i];
// //                     int nc = c + dc[i];
// //                     int newrem = obs;
// //                     if(nr < 0 || nr >= n || nc <0 || nc >= m)continue;
// //                     if(grid[nr][nc] == 1)newrem--;
// //                     if(newrem > vis[nr][nc]){
// //                         vis[nr][nc] = newrem;
// //                         pq.push({steps+1,nr,nc,newrem});
// //                     }
// //                 }
// //             }
// //         }
// //         return -1;
// //     }
// // };

// class Solution {
// public:
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         int n = grid.size();
//         int m = grid[0].size();
//         if (n == 1 && m == 1)
//             return 0;
//         queue<tuple<int, int, int, int>> q;
//         // steps, row, col, remaining k
//         q.push({0, 0, 0, k});
//         vector<vector<int>> visited(n, vector<int>(m, -1));
//         visited[0][0] = k;
//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, 1, 0, -1};
//         while (!q.empty()) {
//             auto [steps, r, c, rem] = q.front();
//             q.pop();
//             for (int i = 0; i < 4; i++) {
//                 int nr = r + dr[i];
//                 int nc = c + dc[i];
//                 // Boundary check
//                 if (nr < 0 || nr >= n || nc < 0 || nc >= m)
//                     continue;
//                 int newRem = rem;
//                 // Eliminate obstacle
//                 if (grid[nr][nc] == 1)
//                     newRem--;
//                 if (newRem < 0)
//                     continue;
//                 if (nr == n - 1 && nc == m - 1)
//                     return steps + 1;
//                 // We only care if this route gives us
//                 // more remaining eliminations.
//                 if (newRem > visited[nr][nc]) {
//                     visited[nr][nc] = newRem;
//                     q.push({steps + 1, nr, nc, newRem});
//                 }
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        if (k >= rows + cols - 2) return rows + cols - 2;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(rows, vector<int>(cols, INT_MAX));

        q.push({{0, 0}, 0});
        vis[0][0] = 0;

        int drc[] = {0, -1, 0, 1, 0};
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [pos, removed] = q.front();
                auto [r, c] = pos;
                q.pop();
                
                if (r == rows - 1 && c == cols - 1 && removed <= k) {
                    return steps;
                }
                
                for (int i = 0; i < 4; i++) {
                    int nr = r + drc[i];
                    int nc = c + drc[i + 1];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        int temp = removed + grid[nr][nc];
                        if (temp <= k && temp < vis[nr][nc]) {
                            vis[nr][nc] = temp;
                            q.push({{nr, nc}, temp});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
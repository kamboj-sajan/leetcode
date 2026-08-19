// Last updated: 19/08/2026, 16:00:18
// // class Solution {
// // public:
// //     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
// //         int n = mat.size();
// //         int m = mat[0].size();
// //         queue<pair<pair<int,int>,int>> q;
// //         vector<vector<int>> ans(n, vector<int>(m, 0));
// //         vector<vector<int>> vis(n, vector<int>(m, 0));
// //         for(int i = 0; i < n; i++){
// //             for(int j = 0; j < m; j++){
// //                 if(mat[i][j] == 0){
// //                     q.push({{i, j}, 0});
// //                     vis[i][j] = 1;
// //                 }
// //             }
// //         }
// //         int dr[] = {-1, 0, 1, 0};
// //         int dc[] = {0, 1, 0, -1};
// //         while(!q.empty()){
// //             auto it = q.front();
// //             q.pop();
// //             int r = it.first.first;
// //             int c = it.first.second;
// //             int dis = it.second;
// //             ans[r][c] = dis;
// //             for(int k = 0; k < 4; k++){
// //                 int nr = r + dr[k];
// //                 int nc = c + dc[k];
// //                 if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
// //                    !vis[nr][nc]){
// //                     vis[nr][nc] = 1;
// //                     q.push({{nr, nc}, dis + 1});
// //                 }
// //             }
// //         }
// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         queue<pair<int,int>> q;
//         vector<vector<int>> ans(n, vector<int>(m, -1));
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(mat[i][j] == 0){
//                     ans[i][j] = 0;
//                     q.push({i, j});
//                 }
//             }
//         }
//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, 1, 0, -1};
//         while(!q.empty()){
//             auto [r, c] = q.front();
//             q.pop();

//             for(int k = 0; k < 4; k++){
//                 int nr = r + dr[k];
//                 int nc = c + dc[k];

//                 if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1){
//                     ans[nr][nc] = ans[r][c] + 1;
//                     q.push({nr, nc});
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto& dir : dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr>= 0 && nr<m && nc>= 0 && nc<n && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c]+1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};
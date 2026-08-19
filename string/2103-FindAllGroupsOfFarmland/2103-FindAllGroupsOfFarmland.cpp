// Last updated: 19/08/2026, 15:34:27
// class Solution {
// public: 
//     vector<vector<int>> ans;
//     void bfs(int r,int c,vector<vector<int>> &land){
//         int n = land.size();
//         int m = land[0].size();
//         vector<int> temp;
//         temp.push_back(r);
//         temp.push_back(c);
//         queue<pair<int,int>> q;
//         int rn = r;
//         int cn = c;
//         q.push({r,c});
//         land[r][c] = 0;
//         int dr[] = {-1,0,1,0};
//         int dc[] = {0,1,0,-1};
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
//             for(int k=0; k<4; k++){
//                 int nr = it.first + dr[k];
//                 int nc = it.second + dc[k];
//                 if(nr >=0 && nr < n && nc >=0 && nc < m && land[nr][nc] == 1){
//                     q.push({nr,nc});
//                     land[nr][nc] = 0;
//                     rn = nr;
//                     cn = nc;
//                 }
//             }
//         }
//         temp.push_back(rn);
//         temp.push_back(cn);
//         ans.push_back(temp);
//     }
// public:
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         int n = land.size();
//         int m = land[0].size();
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(land[i][j] == 1){
//                     bfs(i,j,land);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         vector<vector<int>> result;
//         int m = land.size();
//         int n = land[0].size();
        
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (land[i][j] == 1 && (i == 0 || land[i - 1][j] == 0) && (j == 0 || land[i][j - 1] == 0)) {
//                     int r2 = i;
//                     int c2 = j;
//                     while (r2 + 1 < m && land[r2 + 1][j] == 1) {
//                         r2++;
//                     }
//                     while (c2 + 1 < n && land[i][c2 + 1] == 1) {
//                         c2++;
//                     }
//                     result.push_back({i, j, r2, c2});
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> ans;

    void bfs(int r, int c, vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();

        queue<pair<int,int>> q;
        q.push({r, c});
        land[r][c] = 0;

        int mxr = r, mxc = c;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            mxr = max(mxr, x);
            mxc = max(mxc, y);

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && land[nx][ny] == 1) {
                    land[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        ans.push_back({r, c, mxr, mxc});
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1)
                    bfs(i, j, land);
            }
        }

        return ans;
    }
};
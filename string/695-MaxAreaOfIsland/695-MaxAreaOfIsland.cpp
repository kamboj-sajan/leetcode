// Last updated: 19/08/2026, 15:58:20
// class Solution {
// public: 
//     int maxi = 0;
//     void bfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis,int cnt){
//         int n = grid.size();
//         int m = grid[0].size();
//         vis[r][c] = 1;
//         cnt++;
//         queue<pair<int,int>> q;
//         q.push({r,c});
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
//             int drow[]= {-1,0,1,0};
//             int dcol[] = {0,1,0,-1};
//             for(int k = 0; k<4; k++){
//                 int nr = it.first + drow[k];
//                 int nc = it.second + dcol[k];
//                 if(nr >=0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
//                     cnt++;
//                     vis[nr][nc] = 1;
//                     q.push({nr,nc});
//                 }
//             }
//         }
//         maxi = max(maxi,cnt);
//     }
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n,vector<int> (m,0));
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(!vis[i][j] && grid[i][j] == 1){
//                     bfs(i,j,grid,vis,0);
//                 }
//             }
//         }
//         return maxi;
//     }
// };

// class Solution {
//     int n;
//     int m;
//     vector<vector<int>> grid;
//     vector<vector<int>> directions = {{1, 0},{-1, 0},{0,1},{0,-1}};

//     int findArea(int i, int j){
//         if ((i<0 or i>=n) or (j<0 or j>=m))   return 0;
//         if (grid[i][j] == 0 or grid[i][j] == 2)   return 0;
//         grid[i][j] = 2;
//         int current_area = 1;
//         for(auto& k: directions){
//             current_area += findArea(i+k[0], j+k[1]);
//         }
//         return current_area;
//     }

// public:
//     int maxAreaOfIsland(vector<vector<int>>& _grid) {
//         grid = _grid;
//         n = grid.size();
//         m = grid[0].size();
//         int max_area = 0;
//         for(int i = 0; i< n; i++){
//             for(int j = 0; j < m; j++){
//                 if(grid[i][j] == 1){
//                     max_area = max(max_area, findArea(i, j));
//                 }
//             }
//         }
//         return max_area;
//     }
// };

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return 1 +
               dfs(i - 1, j, grid) +
               dfs(i + 1, j, grid) +
               dfs(i, j - 1, grid) +
               dfs(i, j + 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};
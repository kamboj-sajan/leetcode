// Last updated: 19/08/2026, 15:53:53
// // class Solution {
// // public:
// //     void dfs(vector<vector<int>>& board, int i, int j) {
// //         int m = board.size(), n = board[0].size();

// //         if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 1)
// //             return;

// //         board[i][j] = 2;

// //         dfs(board, i + 1, j);
// //         dfs(board, i - 1, j);
// //         dfs(board, i, j + 1);
// //         dfs(board, i, j - 1);
// //     }

// // public:
// //     int numEnclaves(vector<vector<int>>& board) {
// //         int m = board.size(), n = board[0].size();
// //         if (m == 0 || n == 0) return 0;

// //         // Run DFS from boundary land
// //         for (int i = 0; i < m; i++) {
// //             if (board[i][0] == 1) dfs(board, i, 0);
// //             if (board[i][n - 1] == 1) dfs(board, i, n - 1);
// //         }

// //         for (int j = 0; j < n; j++) {
// //             if (board[0][j] == 1) dfs(board, 0, j);
// //             if (board[m - 1][j] == 1) dfs(board, m - 1, j);
// //         }

// //         // Count enclosed land
// //         int cnt = 0;
// //         for (int i = 0; i < m; i++) {
// //             for (int j = 0; j < n; j++) {
// //                 if (board[i][j] == 1) {
// //                     cnt++;
// //                 }
// //             }
// //         }
// //         return cnt;
// //     }
// // };


// class Solution {
// public:
//     void dfs(vector<vector<int>>& grid,int r,int c){
//         int m = grid.size();
//         int n = grid[0].size();
//         if(r>=m || r<0 || c>=n || c<0 || grid[r][c]==0) return;

//         grid[r][c] = 0;

//         dfs(grid,r+1,c);
//         dfs(grid,r-1,c);
//         dfs(grid,r,c+1);
//         dfs(grid,r,c-1);
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         for(int i=0;i<m;i++){
//             if(grid[i][0]==1) dfs(grid,i,0);
//             if(grid[i][n-1]==1) dfs(grid,i,n-1);
//         }
//         for(int j=0;j<n;j++){
//             if(grid[0][j]==1) dfs(grid,0,j);
//             if(grid[m-1][j]==1) dfs(grid,m-1,j);
//         }
//         int cnt = 0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 1) {
                q.push({i, 0});
                board[i][0]=2;
            }
            if (board[i][m - 1] == 1) {
                q.push({i, m-1});
                board[i][m-1]=2;
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] ==1) {
                q.push({0, j});
                board[0][j]=2;
            }
            if (board[n - 1][j] == 1) {
                q.push({n-1, j});
                board[n-1][j]=2;
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f.first;
            int y = f.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] ==1) {
                    q.push({nx, ny});
                    board[nx][ny] =2;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1)ans++;
            }
        }
        return ans;
    }
};
// Last updated: 19/08/2026, 16:07:44
// class Solution {
// public:
//     void dfs(int i, int j, vector<vector<char>>& board,vector<vector<int>>& vis) {
//         int n = board.size();
//         int m = board[0].size();
//         vis[i][j] = 1;
//         int dr[] = {-1, 0, 1, 0};
//         int dc[] = {0, 1, 0, -1};
//         for (int k = 0; k < 4; k++) {
//             int nr = i + dr[k];
//             int nc = j + dc[k];
//             if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
//                 board[nr][nc] == 'O' && !vis[nr][nc]) {
//                 dfs(nr, nc, board, vis);
//             }
//         }
//         return;
//     }

// public:
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         for (int i = 0; i < n; ++i) {
//             if (!vis[i][0] && board[i][0] == 'O') {
//                 dfs(i, 0, board, vis);
//             }
//             if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
//                 dfs(i, m - 1, board, vis);
//             }
//         }
//         for (int j = 0; j < m; ++j) {
//             if (!vis[0][j] && board[0][j] == 'O') {
//                 dfs(0, j, board, vis);
//             }
//             if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
//                 dfs(n - 1, j, board, vis);
//             }
//         }
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (board[i][j] == 'O' && !vis[i][j]) {
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>&arr){
        if(i<0 or i>=n or j<0 or j>=m or arr[i][j]!='O') return ;
        arr[i][j]='#';
        dfs(i+1,j,n,m,arr);
        dfs(i-1,j,n,m,arr);
        dfs(i,j+1,n,m,arr);
        dfs(i,j-1,n,m,arr);
    }
    void solve(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            dfs(i,0,n,m,arr);
            dfs(i,m-1,n,m,arr);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,n,m,arr);
            dfs(n-1,j,n,m,arr);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='#') arr[i][j]='O';
                else arr[i][j]='X';
            }
        }
    }
};
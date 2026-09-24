// Last updated: 25/09/2026, 01:22:02
// // class Solution {
// // public: 
// //     void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &board){
// //         queue<pair<int,int>> q;
// //         q.push({i,j});
// //         int drc[] = {0,-1,0,1,0};
// //         while(!q.empty()){
// //             auto [r,c] = q.front();
// //             vis[r][c] = 1;
// //             q.pop();
// //             for(int i=0; i<4; i++){
// //                 int nr = r + drc[i];
// //                 int nc = c + drc[i+1];
// //                 if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && !vis[nr][nc] && board[nr][nc] == 'X'){
// //                     q.push({nr,nc});
// //                 }
// //             }
// //         }
// //     }
// // public:
// //     int countBattleships(vector<vector<char>>& board) {
// //        int m = board.size();
// //        int n = board[0].size();
// //        vector<vector<int>> vis(m,vector<int> (n,0));
// //        int cnt = 0;
// //        for(int i=0; i<m; i++){
// //         for(int j=0; j<n; j++){
// //             if(!vis[i][j] && board[i][j] == 'X'){
// //                 cnt++;
// //                 bfs(i,j,vis,board);
// //             }
// //         }
// //        }
// //        return cnt;
// //     }
// // };

// class Solution {
// public:
//     void dfs(vector<vector<bool>>&vis,int x, int y, vector<vector<char>>& board){
//         vis[x][y]=true;
//         int n=board.size();
//         int m=board[0].size();
//         //up
//         if(x-1>=0 && board[x-1][y]=='X' && vis[x-1][y]==false){
//             dfs(vis, x-1, y, board);
//         }
//         //down
//         if(x+1<n && board[x+1][y]=='X' && vis[x+1][y]==false){
//             dfs(vis, x+1, y, board);
//         }
//         //left
//         if(y-1>=0 && board[x][y-1]=='X' && vis[x][y-1]==false){
//             dfs(vis, x, y-1, board);
//         }
//         //right
//         if(y+1<m && board[x][y+1]=='X' && vis[x][y+1]==false){
//             dfs(vis, x, y+1, board);
//         }

//         return;
//     }
//     int countBattleships(vector<vector<char>>& board) {
//         vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
//         int ans=0;
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 if(board[i][j]=='X' && vis[i][j]==false){
//                     ans++;
//                     dfs(vis, i, j, board);
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Empty cell
                if (board[i][j] == '.')
                    continue;

                // Part of a horizontal/vertical battleship
                if (i > 0 && board[i - 1][j] == 'X')
                    continue;

                if (j > 0 && board[i][j - 1] == 'X')
                    continue;

                // This is the first cell of a battleship
                ans++;
            }
        }

        return ans;
    }
};
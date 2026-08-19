// Last updated: 19/08/2026, 15:54:19
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         //{{r,c},t}
//         queue<pair<pair<int,int>, int>> q;
//         int vis[n][m];
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == 2){
//                     q.push({{i,j},0});
//                     vis[i][j] = 2;
//                 }
//                 else{
//                     vis[i][j] = 0;
//                 }
//             }
//         }
//         int tm = 0;
//         int drow[] = {-1,0,+1,0};
//         int dcol[] = {0,1,0,-1};
//         while(!q.empty()){
//             int r = q.front().first.first;
//             int c = q.front().first.second;
//             int t = q.front().second;
//             tm = max(tm,t);
//             q.pop();
//             for(int i=0; i<4; i++){
//                 int nrow = r + drow[i];
//                 int ncol = c + dcol[i];
//                 if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
//                     q.push({{nrow,ncol},t+1});
//                     vis[nrow][ncol] = 2;
//                 }
//             }
//         }
//         // check for any fresh oranges
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(vis[i][j] != 2 && grid[i][j] == 1){
//                     return -1;
//                 }
//             }
//         }
//         return tm;
//     }
// };
/*
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //{{r,c},t}
        n x m sc
        queue<pair<pair<int,int>, int>> q;
        n x m sc
        int vis[n][m];
        int cntfresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) cntfrsh++;
            }
        }
        int tm = 0;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        // check for any fresh oranges
        if(cnt != cntfresh) return -1;
        return tm;
    }
};
*/


// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         queue<pair<int,int>> q;
//         int fresh = 0;

//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 if (grid[i][j] == 2) {
//                     q.push({i, j});
//                 } else if (grid[i][j] == 1) {
//                     fresh++;
//                 }
//             }
//         }

//         int dx[4] = {1, -1, 0, 0};
//         int dy[4] = {0, 0, 1, -1};
//         int minutes = 0;

//         while (!q.empty() && fresh > 0) {
//             int size = q.size();
//             while (size--) {
//                 auto [x, y] = q.front();
//                 q.pop();

//                 for (int d = 0; d < 4; d++) {
//                     int nx = x + dx[d];
//                     int ny = y + dy[d];

//                     if (nx >= 0 && ny >= 0 &&
//                         nx < grid.size() && ny < grid[0].size() &&
//                         grid[nx][ny] == 1) {

//                         grid[nx][ny] = 2;
//                         fresh--;
//                         q.push({nx, ny});
//                     }
//                 }
//             }
//             minutes++;
//         }

//         return fresh == 0 ? minutes : -1;
//     }
// };

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int num_mins = 0;
//         int num_oranges = 0; //to denote the number of oranges that have rotted
//         queue<vector<int>> tracker;
//         int new_row[4] = {-1,0,1,0};
//         int new_col[4] = {0,-1,0,1};

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j]==2){
//                     tracker.push({i,j});
//                 }
//                 else if(grid[i][j]==1){
//                     num_oranges++;
//                 }
//             }
//         }

//         if(num_oranges == 0){
//             //edge case where we have got no fresh oranges
//             return 0;
//         }
//         while(!tracker.empty()){
//             bool rots = false;
//             int len = tracker.size();
//             for(int l=0; l<len; l++){
//                 vector<int> curr_cell = tracker.front();
//                 tracker.pop();
//                 int r = curr_cell[0];
//                 int c = curr_cell[1];
//                 for(int k=0; k<4; k++){
//                     int new_r = r + new_row[k];
//                     int new_c = c + new_col[k];
//                     if(new_r>=0 && new_r < m && new_c>=0 && new_c < n && grid[new_r][new_c]==1){
//                         //rotting the orange
//                         grid[new_r][new_c]=2;
//                         num_oranges--;
//                         tracker.push({new_r,new_c});
//                         rots = true;
//                     }
//                 }
//             }

//             if(rots){
//                 num_mins++;
//             }
            
//         }

//         return num_oranges==0 ? num_mins : -1;
        
//     }
// };

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int cf = 0;
//          queue<pair<int,int>> q;
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == 1)cf++;
//                 else if(grid[i][j] == 2){
//                     q.push({i,j});
//                     grid[i][j] = 0;
//                 }
//             }
//         }
//         if(cf == 0)return 0;
//         int dr[] = {-1,0,1,0};
//         int dc[] = {0,1,0,-1};
//         int t = 0;
//         int co = 0;
//         while(!q.empty()){
//             int sz = q.size();
//             bool rot = false;
//             for(int j=0; j<sz; j++){
//             auto it = q.front();
//             q.pop();
//             for(int k=0; k<4; k++){
//                 int nr = it.first + dr[k];
//                 int nc = it.second + dc[k];
//                 if(nr >=0 && nc >=0 && nr < n && nc < m && grid[nr][nc] == 1){
//                     q.push({nr,nc});
//                     co++;
//                     grid[nr][nc] = 0;
//                     rot = true;
//                 }
//             }
//         }
//         if(rot)t++;
//         }
//         return (co == cf) ? t : -1;
//     }
// };

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int cf = 0;
//         queue<pair<int,int>> q;

//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == 1) cf++;
//                 else if(grid[i][j] == 2){
//                     q.push({i,j});
//                 }
//             }
//         }

//         if(cf == 0) return 0;

//         int dr[] = {-1,0,1,0};
//         int dc[] = {0,1,0,-1};
//         int t = 0;
//         int co = 0;

//         while(!q.empty()){
//             int sz = q.size();
//             bool rotted = false;

//             for(int i=0; i<sz; i++){
//                 auto it = q.front();
//                 q.pop();

//                 for(int k=0; k<4; k++){
//                     int nr = it.first + dr[k];
//                     int nc = it.second + dc[k];

//                     if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1){
//                         q.push({nr,nc});
//                         grid[nr][nc] = 2;
//                         co++;
//                         rotted = true;
//                     }
//                 }
//             }

//             if(rotted) t++;
//         }
//         return (co == cf) ? t : -1;
//     }
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0) return 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int minutes = -1;

        while(!q.empty()){
            int sz = q.size();
            minutes++;

            while(sz--){
                auto [r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
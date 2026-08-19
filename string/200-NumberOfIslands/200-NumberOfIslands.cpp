// Last updated: 19/08/2026, 16:05:20
// class Solution {
// private:
//     void bfs(int row,int col,vector<vector<int>> &vis, vector<vector<char>> &grid){
//         vis[row][col] = 1;
//         queue<pair<int,int>> q;
//         q.push({row,col});
//         int n = grid.size();
//         int m = grid[0].size();
//         while(!q.empty()){
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();
//             //traverse in the neighbour and mark them if its a  land
//             for(int delrow=-1; delrow<=1; delrow++){
//                 int nrow = row + delrow;
//                 if(nrow>=0 && nrow<n && grid[nrow][col] == '1' && !vis[nrow][col]){
//                     vis[nrow][col] = 1;
//                     q.push({nrow,col});

//                 }
//             }
//              for(int delcol=-1; delcol<=1; delcol++){
//                 int ncol = col + delcol;
//                 if( ncol>=0 && ncol<m && grid[row][ncol] == '1' && !vis[row][ncol]){
//                     vis[row][ncol] = 1;
//                     q.push({row,ncol});

//                 }
//             }
//         }
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//      int n = grid.size();
//      int m = grid[0].size();
//      vector<vector<int>> vis(n,vector<int>(m,0));
//      int cnt = 0;
//      for(int row = 0; row<n; row++){
//         for(int col = 0; col<m; col++){
//             if(!vis[row][col] && grid[row][col] == '1'){
//                 cnt ++;
//                 bfs(row,col,vis,grid);
//             }
//         }
//      }   
//      return cnt;
//     }
// };

// class Solution {
// public:
//     void dfs(vector<vector<char>>& grid,int r,int c){
//         if(r<0|| c<0|| r>=grid.size()||c>=grid[0].size()||grid[r][c]=='0')
//         return;
//         grid[r][c]='0';
//         dfs(grid,r,c+1);
//         dfs(grid,r+1,c);
//         dfs(grid,r,c-1);
//         dfs(grid,r-1,c);
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int c=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     dfs(grid,i,j);
//                     c++;
//                 }
//             }
//         }
//         return c;
//     }
// };


// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int islands = 0;
//         int rows = grid.size();
//         int cols = grid[0].size();
//         unordered_set<string> visited;

//         vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (grid[r][c] == '1' && visited.find(to_string(r) + "," + to_string(c)) == visited.end()) {
//                     islands++;
//                     bfs(grid, r, c, visited, directions, rows, cols);
//                 }
//             }
//         }

//         return islands;        
//     }

// private:
//     void bfs(vector<vector<char>>& grid, int r, int c, unordered_set<string>& visited, vector<pair<int, int>>& directions, int rows, int cols) {
//         queue<pair<int, int>> q;
//         visited.insert(to_string(r) + "," + to_string(c));
//         q.push({r, c});

//         while (!q.empty()) {
//             auto [row, col] = q.front();
//             q.pop();

//             for (auto [dr, dc] : directions) {
//                 int nr = row + dr;
//                 int nc = col + dc;
//                 if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && visited.find(to_string(nr) + "," + to_string(nc)) == visited.end()) {
//                     q.push({nr, nc});
//                     visited.insert(to_string(nr) + "," + to_string(nc));
//                 }
//             }
//         }
//     }
// };    


// class Solution {
// public:
//     void dfs(vector<vector<char>>& grid, int m, int n) {
//         grid[m][n] = '0';
//         if (m != 0 && grid[m - 1][n] != '0'){
//             dfs(grid, m - 1, n);
//         }
//         if (n != 0 && grid[m][n - 1] != '0'){
//             dfs(grid, m, n - 1);
//         }
//         if (m < grid.size() - 1 && grid[m + 1][n] != '0'){
//             dfs(grid, m + 1, n);
//         }
//         if (n < grid[0].size() - 1 && grid[m][n + 1] != '0'){
//             dfs(grid, m, n + 1);
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int cnt = 0;
//         for (int m = 0; m < grid.size(); m++)
//         {
//             for (int n = 0; n < grid[0].size(); n++)
//             {
//                 if (grid[m][n] == '1'){
//                     dfs(grid, m, n);
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };


// class Solution {
// public:
//     void bfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &vis){
//         int n = grid.size();
//         int m = grid[0].size();
//         vis[r][c] = 1;
//         queue<pair<int,int>> q;
//         q.push({r,c});
//         while(!q.empty()){
//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();
//             for(int drow = -1; drow <=1; drow++){
//                 int ni = i + drow;
//                 if(ni >= 0 &&ni < n && vis[ni][j] != 1 && grid[ni][j] == '1'){
//                     vis[ni][j] = 1;
//                     q.push({ni,j});
//                 }
//             }
//             for(int dcol = -1; dcol <=1; dcol++){
//                 int nj = j + dcol;
//                 if(nj >=0 && nj < m && !vis[i][nj] && grid[i][nj] == '1'){
//                     vis[i][nj] = 1;
//                     q.push({i,nj});
//                 }
//             }
//         }
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int cnt = 0;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n,vector<int> (m,0));
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(!vis[i][j] && grid[i][j] == '1'){
//                     cnt++;
//                     bfs(i,j,grid,vis);
//                 }
//             }
//         }
//         return cnt;
//     }
// };



// class Solution {
// public:
//     void bfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &vis){
//     int n = grid.size();
//     int m = grid[0].size();

//     queue<pair<int,int>> q;
//     q.push({r,c});
//     vis[r][c] = 1;

//     int dr[] = {-1,0,1,0};
//     int dc[] = {0,1,0,-1};

//     while(!q.empty()){
//         auto [i,j] = q.front();
//         q.pop();

//         for(int k=0;k<4;k++){
//             int ni = i + dr[k];
//             int nj = j + dc[k];

//             if(ni>=0 && ni<n && nj>=0 && nj<m &&
//                !vis[ni][nj] && grid[ni][nj]=='1'){
//                 vis[ni][nj]=1;
//                 q.push({ni,nj});
//             }
//         }
//     }
// }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int cnt = 0;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n,vector<int> (m,0));
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(!vis[i][j] && grid[i][j] == '1'){
//                     cnt++;
//                     bfs(i,j,grid,vis);
//                 }
//             }
//         }
//         return cnt;
//     }
// };


// class Solution {
// public:
//     void dfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &vis){
//     int n = grid.size();
//     int m = grid[0].size();
//     vis[r][c] = 1;
//     int drow[] = {-1,0,1,0};
//     int dcol[] = {0,1,0,-1};
//     for(int k = 0; k < 4; ++k){
//         int nr = r + drow[k];
//         int nc = c + dcol[k];
//         if(nr >=0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]){
//             dfs(nr,nc,grid,vis);
//         }
//     }
// }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int cnt = 0;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> vis(n,vector<int> (m,0));
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(!vis[i][j] && grid[i][j] == '1'){
//                     cnt++;
//                     dfs(i,j,grid,vis);
//                 }
//             }
//         }
//         return cnt;
//     }
// };


static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
private:
    int rows;
    int columns;

    void sinkIsland(vector<vector<char>>& grid, int row, int column) {
        static constexpr std::array<std::pair<int, int>, 4> 
                            directions = {{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}};

        grid[row][column] = '0';

        for(const auto [dx, dy] : directions) {
            auto x = row + dx;
            auto y = column + dy;

            if(x >= 0 && x < rows && y >= 0 && y < columns
                && grid[x][y] == '1') {
                sinkIsland(grid, x, y);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {        
        rows    = grid.size();
        columns = grid.front().size();

        int result = 0;

        for(int row = 0; row < rows; ++row) {
            for(int column = 0; column < columns; ++column) {
                if(grid[row][column] == '1') {
                    ++result;
                    sinkIsland(grid, row, column);
                }
            }
        }

        return result;
    }
};
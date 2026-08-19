// Last updated: 19/08/2026, 15:52:44
// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         if(grid[0][0] == 1)return -1;
//         vector<vector<int>> dist(n,vector<int> (m,1e9));
//         queue<pair<int,pair<int,int>>> q;
//         q.push({1,{0,0}});
//         dist[0][0] = 1;
//         while(!q.empty()){
//             auto it = q.front();
//             q.pop();
//             int diss = it.first;
//             int r = it.second.first;
//             int c = it.second.second;
//             int dr[] = {-1,0,1,0};
//             int dc[] = {0,1,0,-1};
//             for(int i=0; i<4; ++i){
//                 for(int j=0; j<4; ++j){
//                     int nr = r + dr[i];
//                     int nc = c + dc[j];
//                     if(nr < 0 && nr >= n && nc < 0 && nc >0 && grid[nr][nc] == 1)continue;
//                     if(diss + 1 < dist[nr][nc]){
//                         dist[nr][nc] = diss+1;
//                         q.push({diss+1,{nr,nc}});
//                     }
//                 }
//             }
//         }
//         if(dist[n-1][m-1] == 1e9)return -1;
//         return dist[n-1][m-1];
//     }
// };


// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();

//         // If start or end is blocked
//         if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
//             return -1;

//         // 8 directions
//         int dr[8] = {-1,-1,-1,0,0,1,1,1};
//         int dc[8] = {-1,0,1,-1,1,-1,0,1};

//         queue<pair<int,int>> q;
//         q.push({0,0});
//         grid[0][0] = 1;  // mark visited
//         int pathLen = 1;

//         while (!q.empty()) {
//             int sz = q.size();
//             while (sz--) {
//                 auto [r, c] = q.front();
//                 q.pop();

//                 // reached destination
//                 if (r == n-1 && c == n-1)
//                     return pathLen;

//                 for (int i = 0; i < 8; i++) {
//                     int nr = r + dr[i];
//                     int nc = c + dc[i];

//                     if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
//                         grid[nr][nc] = 1; // mark visited
//                         q.push({nr, nc});
//                     }
//                 }
//             }
//             pathLen++;
//         }

//         return -1;
//     }
// };


// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n=grid.size();
//         if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
//         queue<pair<pair<int,int>,int>> q;
//         q.push({{0,0},0});
//         vector<vector<int>> dist(n,vector<int> (n,1e9));
//         dist[0][0]=1;
        
//         while(!q.empty()){
//             int i=q.front().first.first;
//             int j=q.front().first.second;
//             q.pop();
//             for(int x=-1;x<=1;x++){
//                   for(int y=-1;y<=1;y++){
//                      if(x==0 && y==0) continue;
//                          int nr=x+i,nc=j+y;
//                          if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
//                             if(dist[nr][nc]>dist[i][j]+1){
//                                 dist[nr][nc]=dist[i][j]+1;
//                                 q.push({{nr,nc},dist[nr][nc]});
//                             }
//                          }
                     
//                   }
//             }
            
//         }
//         if(dist[n-1][n-1]==1e9) return -1;
//         return dist[n-1][n-1];

//     }
// };

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;   // mark visited

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        int path = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == n - 1)
                    return path;

                for (int k = 0; k < 8; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0) {

                        grid[nr][nc] = 1;   // visited
                        q.push({nr, nc});
                    }
                }
            }

            path++;
        }

        return -1;
    }
};
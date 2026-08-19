// Last updated: 19/08/2026, 15:30:07
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;

        // Step 1: Multi-source BFS
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<n && dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        // Step 2: Max-Min path using priority queue
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n,0));

        pq.push({dist[0][0], {0,0}});

        while(!pq.empty()){
            auto [safe, cell] = pq.top(); pq.pop();
            int x = cell.first, y = cell.second;

            if(x == n-1 && y == n-1) return safe;
            if(vis[x][y]) continue;
            vis[x][y] = 1;

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny]){
                    int newSafe = min(safe, dist[nx][ny]);
                    pq.push({newSafe, {nx, ny}});
                }
            }
        }

        return 0;
    }
};
// Last updated: 19/08/2026, 15:48:31
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Possible directions for each street type
        vector<vector<pair<int,int>>> dir(7);

        dir[1] = {{0,-1}, {0,1}};    // left, right
        dir[2] = {{-1,0}, {1,0}};    // up, down
        dir[3] = {{0,-1}, {1,0}};    // left, down
        dir[4] = {{0,1}, {1,0}};     // right, down
        dir[5] = {{0,-1}, {-1,0}};   // left, up
        dir[6] = {{0,1}, {-1,0}};    // right, up

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Reached destination
            if (x == m - 1 && y == n - 1)
                return true;

            // Explore all possible directions from current street
            for (auto &[dx, dy] : dir[grid[x][y]]) {
                int nx = x + dx;
                int ny = y + dy;

                // Check bounds and not visited
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;

                // Check if next cell connects back
                for (auto &[rdx, rdy] : dir[grid[nx][ny]]) {
                    if (nx + rdx == x && ny + rdy == y) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }
        return false;
    }
};
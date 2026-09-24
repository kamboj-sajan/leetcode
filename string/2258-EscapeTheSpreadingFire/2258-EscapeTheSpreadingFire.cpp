// Last updated: 25/09/2026, 01:05:53
class Solution {
public:

    int n, m;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // BFS from all fire cells
    vector<vector<int>> getFireTime(vector<vector<int>>& grid) {

        vector<vector<int>> fireTime(
            n, vector<int>(m, INT_MAX)
        );

        queue<pair<int,int>> q;

        // Put all fire cells into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    fireTime[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= n ||
                   nc < 0 || nc >= m)
                    continue;

                // Fire cannot cross walls
                if(grid[nr][nc] == 2)
                    continue;

                // Already visited
                if(fireTime[nr][nc] != INT_MAX)
                    continue;

                fireTime[nr][nc] = fireTime[r][c] + 1;

                q.push({nr,nc});
            }
        }

        return fireTime;
    }


    // Can we survive if we wait 'wait' minutes?
    bool canReach(vector<vector<int>>& grid,
                  vector<vector<int>>& fireTime,
                  int wait) {

        // If fire already reaches starting cell
        // before we finish waiting
        if(fireTime[0][0] <= wait)
            return false;

        vector<vector<int>> dist(
            n, vector<int>(m, -1)
        );

        queue<pair<int,int>> q;

        dist[0][0] = wait;
        q.push({0,0});

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            int curTime = dist[r][c];

            // Reached safehouse
            if(r == n-1 && c == m-1)
                return true;

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= n ||
                   nc < 0 || nc >= m)
                    continue;

                if(grid[nr][nc] == 2)
                    continue;

                if(dist[nr][nc] != -1)
                    continue;

                int nextTime = curTime + 1;

                // Safehouse:
                // reaching at the same time as fire is OK.
                if(nr == n-1 && nc == m-1) {

                    if(fireTime[nr][nc] >= nextTime) {
                        dist[nr][nc] = nextTime;
                        q.push({nr,nc});
                    }

                }
                else {

                    // Other cells:
                    // we must arrive strictly before fire.
                    if(fireTime[nr][nc] > nextTime) {

                        dist[nr][nc] = nextTime;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return false;
    }


    int maximumMinutes(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // Step 1: Calculate fire arrival times
        vector<vector<int>> fireTime =
            getFireTime(grid);


        // Step 2: Check if we can wait an arbitrarily
        // large amount of time.
        if(fireTime[0][0] == INT_MAX &&
           canReach(grid, fireTime, 1000000000)) {

            return 1000000000;
        }


        // Step 3: Binary search maximum waiting time
        int low = 0;
        int high = 1000000000;

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canReach(grid, fireTime, mid)) {

                ans = mid;
                low = mid + 1;

            }
            else {

                high = mid - 1;
            }
        }

        return ans;
    }
};
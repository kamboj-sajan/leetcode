// Last updated: 19/08/2026, 15:35:24
// class Solution {
// public:
//     bool dfs(int r,int c,vector<vector<int>> &g1,vector<vector<int>> &g2){
//         int n = g1.size();
//         int m = g2[0].size();
//         g2[r][c] = 0;
//         bool a = (g1[r][c] == 1);
//         int dr[] = {-1,0,1,0};
//         int dc[] = {0,1,0,-1};
//         for(int k=0; k<4; k++){
//             int nr = r + dr[k];
//             int nc = c + dc[k];
//             if(nr >=0 && nr < n && nc >=0 && nc < m && g2[nr][nc] == 1){
//                 a &= dfs(nr,nc,g1,g2);
//             }
//         }
//         return a;
//     }
// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         int n = grid1.size();
//         int m = grid1[0].size();
//         int cnt = 0;
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if (grid2[i][j] == 1) {
//                     if (dfs(i, j, grid1, grid2))
//                         cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };


// class Solution {
// 	// Delta for: up, right, down, left
// 	int dr[4] { -1, 0, 1, 0 };
// 	int dc[4] { 0, 1, 0, -1 };

// 	bool is_sub_island;

// 	// Return true if this position INSIDE the 2D grid2
// 	bool isvalid(int r, int c, vector<vector<int>> &grid2) {
// 		if (r < 0 || r >= (int) grid2.size())
// 			return false;
// 		if (c < 0 || c >= (int) grid2[0].size())
// 			return false;
// 		return true;
// 	}

// public:

// 	void dfs(int r, int c, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
// 		if (!isvalid(r, c, grid2) || grid2[r][c] == 0)
// 			return;

// 		if (grid2[r][c] && !grid1[r][c]) {
// 			is_sub_island = false;	// Grid2 CC still has more cells!
// 			return;
// 		}
// 		grid2[r][c] = 0;	// use the same grid to mark visited

// 		for (int d = 0; d < 4; ++d)
// 			dfs(r + dr[d], c + dc[d], grid1, grid2);
// 	}

// 	int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
// 		int count = 0;
// 		for (int r = 0; r < (int) grid2.size(); ++r) {
// 			for (int c = 0; c < (int) grid2[0].size(); ++c) {
// 				if (grid2[r][c]) {	// A new CC in grid2
// 					is_sub_island = true;
// 					dfs(r, c, grid1, grid2);
// 					count += is_sub_island;
// 				}
// 			}
// 		}
// 		return count;
// 	}
// };

class Solution {
public:
    int n, m;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        grid2[r][c] = 0;

        bool isSub = grid1[r][c];

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid2[nr][nc]) {
                isSub &= dfs(nr, nc, grid1, grid2);
            }
        }

        return isSub;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] && dfs(i, j, grid1, grid2))
                    ans++;
            }
        }

        return ans;
    }
};
// Last updated: 19/08/2026, 15:56:19
// class Solution {
// public:
//     bool isMagic(int r, int c, vector<vector<int>>& grid) {
//         // 1. Center must be 5
//         if (grid[r+1][c+1] != 5) return false;

//         // 2. Check numbers 1..9 exactly once
//         vector<bool> seen(10, false);
//         for (int i = r; i < r + 3; ++i) {
//             for (int j = c; j < c + 3; ++j) {
//                 int x = grid[i][j];
//                 if (x < 1 || x > 9 || seen[x]) return false;
//                 seen[x] = true;
//             }
//         }

//         int s = grid[r][c] + grid[r][c+1] + grid[r][c+2];

//         // 3. Rows
//         for (int i = 0; i < 3; ++i) {
//             if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != s)
//                 return false;
//         }

//         // 4. Columns
//         for (int j = 0; j < 3; ++j) {
//             if (grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != s)
//                 return false;
//         }

//         // 5. Diagonals
//         if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != s)
//             return false;
//         if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != s)
//             return false;

//         return true;
//     }

//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         int cnt = 0;

//         for (int i = 0; i + 2 < n; ++i) {
//             for (int j = 0; j + 2 < m; ++j) {
//                 if (isMagic(i, j, grid)) cnt++;
//             }
//         }
//         return cnt;
//     }
// };


// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int ans = 0;
//         int m = grid.size();
//         int n = grid[0].size();
//         for (int row = 0; row + 2 < m; row++) {
//             for (int col = 0; col + 2 < n; col++) {
//                 if (isMagicSquare(grid, row, col)) {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }

// private:
//     bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
//         bool seen[10] = {false};
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 int num = grid[row + i][col + j];
//                 if (num < 1 || num > 9) return false;
//                 if (seen[num]) return false;
//                 seen[num] = true;
//             }
//         }

//         // Check if diagonal sums are the same
//         int diagonal1 =
//             grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
//         int diagonal2 =
//             grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

//         if (diagonal1 != diagonal2) return false;

//         // Check if all row sums are the same as the diagonal sums
//         int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
//         int row2 = grid[row + 1][col] + grid[row + 1][col + 1] +
//                    grid[row + 1][col + 2];
//         int row3 = grid[row + 2][col] + grid[row + 2][col + 1] +
//                    grid[row + 2][col + 2];

//         if (!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1)) {
//             return false;
//         }

//         // Check if all column sums are the same as the diagonal sums
//         int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
//         int col2 = grid[row][col + 1] + grid[row + 1][col + 1] +
//                    grid[row + 2][col + 1];
//         int col3 = grid[row][col + 2] + grid[row + 1][col + 2] +
//                    grid[row + 2][col + 2];

//         if (!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal1)) {
//             return false;
//         }

//         return true;
//     }
// };

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), ans = 0;
        if (r < 3 || c < 3) return 0;

        for (int i = 0; i + 2 < r; i++) {
            for (int j = 0; j + 2 < c; j++) {
                bool used[10] = {};
                bool ok = true;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int v = grid[i + x][j + y];
                        if (v < 1 || v > 9 || used[v]) {
                            ok = false;
                            break;
                        }
                        used[v] = true;
                    }
                    if (!ok) break;
                }
                if (!ok) continue;

                int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                for (int x = 0; x < 3; x++)
                    if (grid[i+x][j] + grid[i+x][j+1] + grid[i+x][j+2] != s) ok = false;
                for (int y = 0; y < 3; y++)
                    if (grid[i][j+y] + grid[i+1][j+y] + grid[i+2][j+y] != s) ok = false;
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s) ok = false;
                if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s) ok = false;

                if (ok) ans++;
            }
        }
        return ans;
    }
};
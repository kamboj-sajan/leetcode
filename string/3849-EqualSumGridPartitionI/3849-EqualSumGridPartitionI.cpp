// Last updated: 19/08/2026, 15:24:50
// class Solution {
// public:
//     bool canPartitionGrid(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         // Step 1: total sum
//         long long tot = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 tot += grid[i][j];
//             }
//         }
//         if (tot % 2) return false;
//         long long half = tot / 2;
//         // ✅ Step 2: Row prefix (horizontal cuts)
//         vector<long long> rowSum(m, 0);
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 rowSum[i] += grid[i][j];
//             }
//         }
//         vector<long long> rowPre(m, 0);
//         rowPre[0] = rowSum[0];
//         for (int i = 1; i < m; i++) {
//             rowPre[i] = rowPre[i - 1] + rowSum[i];
//         }
//         for (int i = 0; i < m - 1; i++) {
//             if (rowPre[i] == half) return true;
//         }
//         // ✅ Step 3: Column prefix (vertical cuts)
//         vector<long long> colSum(n, 0);
//         for (int j = 0; j < n; j++) {
//             for (int i = 0; i < m; i++) {
//                 colSum[j] += grid[i][j];
//             }
//         }
//         vector<long long> colPre(n, 0);
//         colPre[0] = colSum[0];
//         for (int j = 1; j < n; j++) {
//             colPre[j] = colPre[j - 1] + colSum[j];
//         }
//         for (int j = 0; j < n - 1; j++) {
//             if (colPre[j] == half) return true;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool canPartitionGrid(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         long long total = 0;
//         // total sum
//         for (auto &row : grid) {
//             for (int val : row) {
//                 total += val;
//             }
//         }
//         if (total % 2) return false;
//         long long half = total / 2;
//         // ✅ Check horizontal cuts
//         long long curr = 0;
//         for (int i = 0; i < m - 1; i++) {
//             for (int j = 0; j < n; j++) {
//                 curr += grid[i][j];
//             }
//             if (curr == half) return true;
//         }
//         // ✅ Check vertical cuts
//         curr = 0;
//         for (int j = 0; j < n - 1; j++) {
//             for (int i = 0; i < m; i++) {
//                 curr += grid[i][j];
//             }
//             if (curr == half) return true;
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        // total sum
        for (auto &row : grid) {
            for (auto &val : row) {
                total += val;
            }
        }

        // if odd → impossible
        if (total % 2 != 0) return false;

        long long target = total / 2;

        // 🔹 check horizontal cut
        long long curr = 0;
        for (int i = 0; i < m - 1; i++) {  // m-1 because last row not allowed
            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            if (curr == target) return true;
        }

        // 🔹 check vertical cut
        curr = 0;
        for (int j = 0; j < n - 1; j++) {  // n-1 because last column not allowed
            for (int i = 0; i < m; i++) {
                curr += grid[i][j];
            }
            if (curr == target) return true;
        }

        return false;
    }
};
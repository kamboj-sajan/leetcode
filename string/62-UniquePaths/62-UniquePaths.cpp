// Last updated: 19/08/2026, 16:11:02
/* optimal solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res = 1;
        for(int i=1; i<=r; i++){
            res = res*(N-r+i)/i;
        }
        return (int)res;
    }
};
*/
// dp solution
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> prev(n,0);
//         for(int i=0; i<m; i++){
//             vector<int> temp(n,0);
//             for(int j=0; j<n; j++){
//                 if(i==0 && j==0)temp[j] = 1;
//                 else{
//                     int up = 0;
//                     int left = 0;
//                     if(i>0)up = prev[j];
//                     if(j>0)left = temp[j-1];
//                     temp[j] = up + left;
//                 }
//             }
//             prev = temp;
//         }
//         return prev[n-1];
//     }
// };

// class Solution {
// public:
//     int uniquePaths(int m, int n, int i = 0, int j = 0) {
//         if(i >= m || j >= n) return 0;                                    // reached out of bounds - invalid
//         if(i == m-1 && j == n-1) return 1;                                // reached the destination - valid solution
//         return uniquePaths(m, n, i+1, j) + uniquePaths(m, n, i, j+1);     // try both down and right
//     }
// };

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n));
//         return dfs(dp, 0, 0);
//     }
//     int dfs(vector<vector<int>>& dp, int i, int j) {
//         if(i >= size(dp)   || j >= size(dp[0]))   return 0;     // out of bounds - invalid
//         if(i == size(dp)-1 && j == size(dp[0])-1) return 1;     // reached end - valid path
//         if(dp[i][j]) return dp[i][j];                           // directly return if already calculated
//         return dp[i][j] = dfs(dp, i+1, j) + dfs(dp, i, j+1);    // store the result in dp[i][j] and then return
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];   // sum of unique paths ending at adjacent top and left cells
        return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
    }
};
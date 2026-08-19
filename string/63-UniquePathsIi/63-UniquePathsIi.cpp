// Last updated: 19/08/2026, 16:10:56
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         vector<int> prev(m,0);
//         for(int i=0; i<n; i++){
//             vector<int> cur(m,0);
//                 for(int j=0; j<m; j++){
//                     if(obstacleGrid[i][j] == 1)cur[j] = 0;
//                     else if(i == 0 && j==0)cur[j]  = 1;
//                     else{
//                         int up = 0; 
//                         int left = 0;
//                         if(i>0)up = prev[j];
//                         if(j>0)left = cur[j-1];
//                         cur[j] = up+left;
//                     }
//                 }
//                 prev = cur;

//         }
//         return prev[m-1];
//     }
// };

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    // dp[i][j] := the number of unique paths from (0, 0) to (i, j)
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
    dp[0][1] = 1;  // Can also set dp[1][0] = 1.

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (!obstacleGrid[i - 1][j - 1])
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m][n];
  }
};
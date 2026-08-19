// Last updated: 19/08/2026, 16:10:51
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<int> prev(m,0);
//         //n
//         for(int i=0; i<n; i++){
//             vector<int> cur(m,0);
//             for(int j=0; j<m; j++){
//                 if(i==0 && j==0)cur[j] = grid[i][j];
//                 else{
//                 int up = grid[i][j];
//                 // req. prev row j column
//                 if(i>0)up += prev[j];
//                 else up += 1e9;
//                 int left = grid[i][j];
//                 //cur row j-1 column
//                 if(j>0)left += cur[j-1];
//                 else left += 1e9;
//                 cur[j] = min(up,left);
//                 }
//             }
//             prev = cur;
//         }
//         return prev[m-1];
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};
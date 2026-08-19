// Last updated: 19/08/2026, 15:48:43
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int cnt = 0;
//         for(int i=0; i<n; ++i){
//             for(int j=m-1; j>=0; --j){
//                 if(grid[i][j] < 0)cnt++;
//                 else break;
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         int count =0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                  if(grid[i][j]<0)count++;
//             }
//         }
//         return count;
//     }
// };
//

//staircase method 
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         int i = m - 1, j = 0;

//         int res = 0;

//         while (i >= 0 && j < n) {
//             if (grid[i][j] < 0) {
//                 res += n - j;
//                 i--;
//             } else
//                 j++;
//         }

//         return res;
//     }
// };

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] < 0) {
                    count += grid[i].size() - j;
                    break;
                }
            }
        }       
        return count;
    }
};
// Last updated: 19/08/2026, 15:38:45
// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//        int n = mat.size();
//        int m = mat[0].size();
//         vector<int> row(n,0);
//         vector<int> col(m,0);
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(mat[i][j] == 1){
//                     row[i]++;
//                     col[j]++;
//                 }
//             }
//         }
//         int cnt = 0;
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<m; ++j){
//                 if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         int ans = 0;
//         for(int i = 0; i < m; i++){
//             int colIndex = -1, count = 0;
//             // count ones in row
//             for(int j = 0; j < n; j++){
//                 if(mat[i][j]){
//                     count++;
//                     colIndex = j;
//                 }
//             }
//             if(count == 1){
//                 bool special = true;
//                 // check column
//                 for(int k = 0; k < m; k++){
//                     if(k != i && mat[k][colIndex] == 1){
//                         special = false;
//                         break;
//                     }
//                 }
//                 if(special) ans++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    bool check(vector<vector<int>>& mat, int x, int y){
        for(int i=0;i<mat.size();i++) {
            if(i == x) continue;
            if(mat[i][y] == 1) return false;
        }
        for(int j=0;j<mat[0].size();j++) {
            if(j == y) continue;
            if(mat[x][j] == 1) return false;
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1) if(check(mat, i, j)) ans++;
            }
        }
        return ans;
    }
};
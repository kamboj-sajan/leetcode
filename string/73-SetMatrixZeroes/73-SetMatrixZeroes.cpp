// Last updated: 19/08/2026, 16:10:28
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n  = matrix[0].size();
//         int col0 = 1;
//      for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(matrix[i][j] == 0){
//                 // mark the ith row
//                 matrix[i][0] = 0;
//                 // mark the jth col
//                 if(j != 0){
//                     matrix[0][j] = 0;
//                 }else{
//                     col0 = 0;
//                 }
//             }
//         }
//      }   
//      for(int i=1; i<m; i++){
//         for(int j=1; j<n; j++){
//             if(matrix[i][j] != 0){
//                 // check for col and row
//                 if(matrix[0][j] == 0 || matrix[i][0] == 0){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//      }
//      if(matrix[0][0] == 0){
//         for(int j=0; j<n; j++) matrix[0][j] = 0;
//      }
//      if(col0 == 0){
//         for(int i = 0; i<m; i++){
//             matrix[i][0] = 0;
//         }
//      }
//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        // vector <int> col(m, 0); -> matrix[0][...]
        // vector <int> row(n, 0); -> matrix[...][0]
        for (int i=0; i<n; i++) {
            for (int j =0; j<m; j++) {
                if (matrix[i][j] == 0) {
                    // mark th ith row
                    matrix[i][0] = 0;
                    if (j!=0) {
                        // mark thejth col
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (matrix[i][j] != 0) {
                    // check for col and row
                    if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j=0; j<m; j++) matrix[0][j] = 0;
        }
        if(col0 == 0) {
            for (int i=0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
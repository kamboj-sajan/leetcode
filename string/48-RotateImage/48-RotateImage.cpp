// Last updated: 19/08/2026, 16:11:55
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//      int n = matrix.size();
//      // transpose
//      //O(N/2 * N/2)
//      for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             swap(matrix[i][j],matrix[j][i]);
//         }
//      }   
//      // reverse
//      // O(N * N/2)
//      for(int i=0; i<n; i++){
//         // row is mat[i]
//         reverse(matrix[i].begin(), matrix[i].end());
//      }
//     }
// };

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n ; i++) {
            for (int j = i; j < n ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(start<=end){
                swap(matrix[i][start],matrix[i][end]);
                start++,end--;
            }
        }
    }
};
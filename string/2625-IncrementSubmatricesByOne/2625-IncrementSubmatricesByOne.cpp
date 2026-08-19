// Last updated: 19/08/2026, 15:30:54
// class Solution {
// public:
//     void f(vector<int> &vec, int n,vector<vector<int>> &ans){
//         int r1 = vec[0];
//         int c1 = vec[1];
//         int r2 = vec[2];
//         int c2 = vec[3];
//         for(int i=r1; i<=r2; ++i){
//             for(int j=c1; j<=c2; ++j){
//                 ans[i][j]++;
//             }
//         }
//         return;
//     }
//     vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
//         vector<vector<int>> ans(n,vector<int> (n,0));
//         for(int i=0; i<queries.size(); ++i){
//             f(queries[i],n,ans);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> arr(n+1,vector<int>(n,0));
        for(auto &q : queries){
            const int r1 = q[0];
            const int c1 = q[1];
            const int r2 = q[2];
            const int c2 = q[3];
            arr[r1][c1]++;
            arr[r2+1][c1]--;
            if(c2 + 1 < n){
                arr[r1][c2+1]--;
                arr[r2+1][c2+1]++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<n; ++j){
                arr[i][j] += arr[i][j-1];
            }
        }
        for(int j=0; j<n; ++j){
            for(int i=1; i<n; ++i){
                arr[i][j] += arr[i-1][j];
            }
        }
        arr.resize(n);
        return arr;
    }
};
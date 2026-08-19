// Last updated: 19/08/2026, 15:24:15
// class Solution {
// public:
//     vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));
//         for(int i=0; i<=m-k; ++i){
//             for(int j=0; j<=n-k; ++j){
//                 set<int> st;
//                 for(int r=i; r<= i+k-1; r++){
//                     for(int c=j; c<= j +k-1; c++){
//                         st.insert(grid[r][c]);
//                     }
//                 }
//                 if(st.size() == 1){
//                     ans[i][j] = 0;
//                     continue;
//                 }
//                 int abd = INT_MAX;
//                 auto prv = st.begin();
//                 auto cur = next(prv);
//                 while(cur != st.end()){
//                     abd = min(abd,abs(*cur - *prv));
//                     prv = cur;
//                     cur++;
//                 }
//                 ans[i][j] = abd;
//             }
//         }
//         return ans;
//     }
// };

// // class Solution {
// // public:
// //     vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
// //         int m = grid.size();
// //         int n = grid[0].size();
// //         vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
// //         for(int i = 0; i <= m - k; ++i){
// //             for(int j = 0; j <= n - k; ++j){
// //                 set<int> st;
// //                 // collect elements
// //                 for(int r = i; r < i + k; r++){
// //                     for(int c = j; c < j + k; c++){
// //                         st.insert(grid[r][c]);
// //                     }
// //                 }
// //                 // if all elements same
// //                 if(st.size() == 1){
// //                     ans[i][j] = 0;
// //                     continue;
// //                 }
// //                 // copy set to vector
// //                 vector<int> v(st.begin(), st.end());
// //                 int abd = INT_MAX;
// //                 // compare adjacent values
// //                 for(int x = 1; x < v.size(); x++){
// //                     abd = min(abd, abs(v[x] - v[x - 1]));
// //                 }
// //                 ans[i][j] = abd;
// //             }
// //         }

// //         return ans;
// //     }
// // };


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> v;
                for (int x = i; x < i + k; x++)
                    for (int y = j; y < j + k; y++)
                        v.push_back(grid[x][y]);

                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());

                if (v.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int mn = INT_MAX;
                    for (int p = 0; p < (int)v.size() - 1; p++)
                        mn = min(mn, v[p+1] - v[p]);
                    ans[i][j] = mn;
                }
            }
        }
        return ans;
    }
};

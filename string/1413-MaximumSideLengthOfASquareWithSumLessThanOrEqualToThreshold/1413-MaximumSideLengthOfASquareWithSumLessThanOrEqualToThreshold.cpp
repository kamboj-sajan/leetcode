// Last updated: 19/08/2026, 15:49:57
// class Solution {
// public:
//     int getsum(int r1,int c1,int r2,int c2,vector<vector<int>> &pref){
//         return pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1]; 
//     }
// public:
//     int maxSideLength(vector<vector<int>>& mat, int threshold) {
//        int n = mat.size();
//        int m = mat[0].size();
//        vector<vector<int>> pref(n+1,vector<int> (m+1,0));
//        for(int i=1; i<=n; ++i){
//         for(int j=1; j<=m; ++j){
//             pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
//         }
//        }
//        int low = 0;
//        int high = min(n,m);
//        int ans = 0;
//        while(low <= high){
//         int mid = (low + high)/2;
//         bool ok = false;
//         for(int i=0; i+mid <= n; ++i){
//             for(int j=0; j+mid<=m; ++j){
//                 if(getsum(i,j,i+mid,j+mid,pref) <= threshold){
//                     ok = true;
//                     break;
//                 }
//             }
//             if(ok)break;
//         }
//         if(ok){
//             ans = mid;
//             low = mid+1;
//         }else{
//             high = mid-1;
//         }
//        }
//        return ans;
//     }
// };

class Solution {
public:
    bool isValid(vector<vector<int>>& pref, int k, int limit) {
        int n = pref.size();
        int m = pref[0].size();

        for (int i = k - 1; i < n; i++) {
            for (int j = k - 1; j < m; j++) {
                int x1 = i - k + 1;
                int y1 = j - k + 1;

                int sum = pref[i][j]
                        - (x1 > 0 ? pref[x1 - 1][j] : 0)
                        - (y1 > 0 ? pref[i][y1 - 1] : 0)
                        + (x1 > 0 && y1 > 0 ? pref[x1 - 1][y1 - 1] : 0);

                if (sum <= limit)
                    return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref = mat;

        // Row-wise prefix sum
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                pref[i][j] += pref[i][j - 1];

        // Column-wise prefix sum
        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
                pref[i][j] += pref[i - 1][j];

        int low = 1, high = min(n, m);
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(pref, mid, threshold)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
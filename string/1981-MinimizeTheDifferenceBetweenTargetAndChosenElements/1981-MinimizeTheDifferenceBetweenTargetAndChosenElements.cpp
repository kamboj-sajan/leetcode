// Last updated: 25/09/2026, 01:07:56
// // class Solution {
// // public:
// //     int n;
// //     int m;
// //     int mini;
// //     void f(int i,vector<vector<int>>& mat,int tg){
// //         if(i == n){
// //             mini = min(mini,abs(tg));
// //             return;
// //         }
// //         for(int j=0; j<m; j++){
// //             f(i+1,mat,tg-mat[i][j]);
// //         }
// //     }
// // public:
// //     int minimizeTheDifference(vector<vector<int>>& mat, int target) {
// //         n = mat.size();
// //         mini = INT_MAX;
// //         m = mat[0].size();
// //         f(0,mat,target);
// //         return mini;
// //     }
// // };

// class Solution {
// public:
//     int n;
//     int m;
//     vector<vector<int>> dp;
//     int f(int i,vector<vector<int>>& mat,int sum,int tg){
//         if(i == n){
//             return abs(sum - tg);
//         }
//         if(dp[i][sum] != -1)return dp[i][sum];
//         int ans = INT_MAX;
//         for(int j=0; j<m; j++){
//             ans = min(f(i+1,mat,sum+mat[i][j],tg),ans);
//         }
//         return dp[i][sum] = ans;
//     }
// public:
//     int minimizeTheDifference(vector<vector<int>>& mat, int target) {
//         n = mat.size();
//         m = mat[0].size();
//         int mx = 0;
//         for(int i=0; i<n; i++){
//             int maxi = INT_MIN;
//             for(int j=0; j<m; j++){
//                 maxi = max(maxi,mat[i][j]);
//             }
//             mx += maxi;
//         }
//         dp.assign(n,vector<int> (mx+1,-1));
//         return f(0,mat,0,target);
//     }
// };

// class Solution {
// public:
//     int minimizeTheDifference(vector<vector<int>>& mat, int target) {
//         const int m = mat.size();
//         const int n = mat[0].size();
//         bitset<801> b{};
//         b.set(0);
//         int minsum{0};
//         for(const auto &row : mat){
//             bitset<801> temp{};
//             int minimum{70};
//             for(const auto& m: row){
//                 temp |= b<<m;
//                 minimum = min(minimum,m);
//             }
//             minsum += minimum;
//             swap(b,temp);
//         }
//         if(minsum > target){return minsum - target;}
//         int ans{800};
//         for(int i{1}; i<801; i++){
//             ans = (b.test(i)) ? min(ans,abs(target - i)) : ans;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        bitset<801> dp;
        dp[0] = 1;

        int minSum = 0;

        for (auto row : mat) {

            bitset<801> newDp;

            int minimum = 70;

            for (int x : row) {

                // If sum is possible before,
                // then sum + x is possible now
                newDp |= (dp << x);

                minimum = min(minimum, x);
            }

            dp = newDp;
            minSum += minimum;
        }

        // If even the minimum possible sum
        // is greater than target, this is the answer
        if (minSum > target) {
            return minSum - target;
        }

        int answer = 800;

        // Check every possible sum
        for (int sum = target; sum <= 800; sum++) {

            if (dp[sum]) {
                answer = min(answer, sum - target);
            }
        }

        // Also check sums smaller than target
        for (int sum = 0; sum < target; sum++) {

            if (dp[sum]) {
                answer = min(answer, target - sum);
            }
        }

        return answer;
    }
};

// Last updated: 19/08/2026, 15:26:22
// class Solution {
// public:
//     int maxi = INT_MIN;
//     void f(int i,int j,int temp,int used,vector<vector<int>> &coins){
//         if(coins[i][j] >=0){
//             temp += coins[i][j];
//         }else{
//             int lt = temp + coins[i][j];
//             if(used < 2){
//                 if(i == 0 && j ==0){
//                     maxi = max(maxi,temp);
//                 }else{
//                     if(i>0)f(i-1,j,temp,used+1,coins);
//                     if(j > 0)f(i,j-1,temp,used+1,coins);
//                 }
//             }
//             temp = lt;
//         }
//         if(i ==0 && j ==0){
//             maxi = max(maxi,temp);
//             return;
//         }
//         if(i>0)f(i-1,j,temp,used,coins);
//         if(j > 0)f(i,j-1,temp,used,coins);
//     }
// public:
//     int maximumAmount(vector<vector<int>>& coins) {
//         int m = coins.size();
//         int n = coins[0].size();
//         f(m-1,n-1,0,0,coins);
//         return maxi;
//     }
// };



// class Solution {
// public:
//     int m, n;
//     vector<vector<int>> coins;
//     vector<vector<vector<int>>> dp;
//     int f(int i, int j, int k) {
//         // out of bounds
//         if(i < 0 || j < 0) return INT_MIN;
//         // base case
//         if(i == 0 && j == 0) {
//             if(coins[0][0] >= 0) return coins[0][0];
//             else {
//                 if(k > 0) return 0;              // neutralize
//                 else return coins[0][0];         // take loss
//             }
//         }
//         // memo
//         if(dp[i][j][k] != INT_MIN) return dp[i][j][k];
//         int best = INT_MIN;
//         // from top
//         int up = f(i-1, j, k);
//         if(up != INT_MIN) {
//             if(coins[i][j] >= 0) {
//                 best = max(best, up + coins[i][j]);
//             } else {
//                 // take loss
//                 best = max(best, up + coins[i][j]);
//                 // neutralize
//                 if(k > 0)
//                     best = max(best, f(i-1, j, k-1));
//             }
//         }
//         // from left
//         int left = f(i, j-1, k);
//         if(left != INT_MIN) {
//             if(coins[i][j] >= 0) {
//                 best = max(best, left + coins[i][j]);
//             } else {
//                 best = max(best, left + coins[i][j]);
//                 if(k > 0)
//                     best = max(best, f(i, j-1, k-1));
//             }
//         }
//         return dp[i][j][k] = best;
//     }
//     int maximumAmount(vector<vector<int>>& c) {
//         coins = c;
//         m = coins.size();
//         n = coins[0].size();
//         dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
//         return max({f(m-1, n-1, 0), f(m-1, n-1, 1), f(m-1, n-1, 2)});
//     }
// };


class Solution {
public:
    int m, n;
    vector<vector<int>> coins;
    vector<vector<vector<int>>> dp;
    int f(int i, int j, int k) {
        if(i == m-1 && j == n-1){
            if(coins[i][j] > 0)return coins[i][j];
            else{
                if(k > 0)return 0;
                else return coins[i][j];
            }
        }
        if(i >= m || j >= n) return INT_MIN;
        if(dp[i][j][k] != INT_MIN)return dp[i][j][k];
        int take = coins[i][j] + max(f(i+1,j,k),f(i,j+1,k));
        int skip = INT_MIN;
        if(coins[i][j] < 0 && k > 0){
            int skipd = f(i+1,j,k-1);
            int skipr = f(i,j+1,k-1);
            skip = max(skipd,skipr);
        }
        return dp[i][j][k] = max(take,skip);
    }
    int maximumAmount(vector<vector<int>>& c) {
        coins = c;
        m = coins.size();
        n = coins[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return f(0,0,2);
    }
};
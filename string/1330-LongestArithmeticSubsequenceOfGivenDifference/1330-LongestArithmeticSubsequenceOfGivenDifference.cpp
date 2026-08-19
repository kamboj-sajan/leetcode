// Last updated: 19/08/2026, 15:50:48
// class Solution {
// public:
//     int f(int i,int prv, vector<int> &arr,int d,vector<vector<int>> &dp){
//         if(i == arr.size())return 0;
//         if(dp[i][prv+1] != -1)return dp[i][prv+1];
//         int nottake = 0 + f(i+1,prv,arr,d,dp);
//         int take = 0;
//         if(prv == -1 || (arr[i] - arr[prv]) == d){
//             take = 1 + f(i+1,i,arr,d,dp);
//         }
//         return dp[i][prv+1] = max(take,nottake);
//     }
// public:
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int n = arr.size();
//         vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
//         return f(0,-1,arr,difference,dp);
//     }
// };

// class Solution {
// public:
//     int longestSubsequence(vector<int>& arr, int difference) {
//         unordered_map<int,int> dp;
//         int ans = 0;
//         for (int x : arr) {
//             dp[x] = dp[x - difference] + 1;
//             ans = max(ans, dp[x]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp; // Stores the maximum length at each index
        
        int ans = 1; // Initialize with the minimum length of 1
        
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (dp.find(num - difference) != dp.end()) {
                dp[num] = dp[num - difference] + 1;
            } else {
                dp[num] = 1;
            }
            
            ans = max(ans, dp[num]);
        }
        
        return ans;
    }
};
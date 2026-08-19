// Last updated: 19/08/2026, 16:05:29
// class Solution {
// /* private:
//     int f(int ind,vector<int>&nums,vector<int> & dp){
//         if(ind == 0)return nums[ind];
//         if(ind < 0)return 0;
//         if(dp[ind] != -1)return dp[ind];
//         int pick = nums[ind] + f(ind-2,nums,dp);
//         int notPick = 0 + f(ind-1,nums,dp);
//         return dp[ind] = max(pick,notPick);
//     }
//     */
// public:
//     int rob(vector<int>& nums) {
//       int n = nums.size();
//        // vector<int> dp(n,-1);
//        // return f(n-1,nums,dp);
//        int prev = nums[0];
//        int prev2 = 0;
//        for(int i=1; i<n; i++){
//         int take = nums[i];
//         if(i>1)take += prev2;
//         int notTake = 0 + prev;
//        int cur = max(take,notTake);
//         prev2 = prev;
//         prev = cur;
//        }
//        return prev;
//     }
// };

// class Solution {
// public:
//     int solve(int i, vector<int>& nums) {
//         if (i >= nums.size()) return 0;
//         int take = nums[i] + solve(i + 2, nums);
//         int skip = solve(i + 1, nums);
//         return max(take, skip);
//     }

//     int rob(vector<int>& nums) {
//         return solve(0, nums);
//     }
// };


// class Solution {
// public:
//     int solve(int i, vector<int>& nums, vector<int>& dp) {
//         if (i >= nums.size()) return 0;
//         if (dp[i] != -1) return dp[i];
//         int take = nums[i] + solve(i + 2, nums, dp);
//         int skip = solve(i + 1, nums, dp);
//         return dp[i] = max(take, skip);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         return solve(0, nums, dp);
//     }
// };

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 0);
//         dp[0] = 0;
//         dp[1] = nums[0];
//         for (int i = 2; i <= n; i++) {
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
//         }
//         return dp[n];
//     }
// };


class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]
        for (int x : nums) {
            int cur = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};



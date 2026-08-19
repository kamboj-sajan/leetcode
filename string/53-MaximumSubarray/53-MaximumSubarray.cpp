// Last updated: 19/08/2026, 16:11:33
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int maxi = INT_MIN;
//         for(auto it:nums){
//             sum += it;
//             maxi = max(sum,maxi);
//             if(sum < 0) sum = 0;
//         }
//         return maxi;
//     }
// };kadane algo
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // dp[i] := the maximum sum subarray ending in i
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    return ranges::max(dp);
  }
};
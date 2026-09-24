// Last updated: 25/09/2026, 01:03:23
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i] = max jumps to reach i
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) continue; // cannot reach this index

            for (int j = i + 1; j < n; j++) {
                if (abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
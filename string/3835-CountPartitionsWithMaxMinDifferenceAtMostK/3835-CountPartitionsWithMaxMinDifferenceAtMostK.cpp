// Last updated: 19/08/2026, 15:24:56
class Solution {
const int MOD = 1000000007;
public:
    int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1), pref(n + 1);
    dp[0] = 1;
    pref[0] = 1;
    deque<int> mx, mn;
    int left = 0;
    for (int i = 0; i < n; ++i) {
        while (!mx.empty() && nums[mx.back()] <= nums[i]) mx.pop_back();
        mx.push_back(i);
        while (!mn.empty() && nums[mn.back()] >= nums[i]) mn.pop_back();
        mn.push_back(i);

        while (!mx.empty() && !mn.empty() &&
               nums[mx.front()] - nums[mn.front()] > k) {
            if (mx.front() == left) mx.pop_front();
            if (mn.front() == left) mn.pop_front();
            left++;
        }

        int idx = i + 1;
        if (left == 0) dp[idx] = pref[i];
        else {
            dp[idx] = pref[i] - pref[left - 1];
            if (dp[idx] < 0) dp[idx] += MOD;
        }

        pref[idx] = pref[idx - 1] + dp[idx];
        if (pref[idx] >= MOD) pref[idx] -= MOD;
    }
    return dp[n];
    }
};
// Last updated: 19/08/2026, 15:20:03
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> l(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= nums[i - 1])
                l[i] = l[i - 1] + 1;
        }
        vector<int> r(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1])
                r[i] = r[i + 1] + 1;
        }
        int ans = 0;
        for (int len : l) {
            ans = max(ans, len);
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans = max(ans, l[i - 1] + 1);
            }
            if (i < n - 1) {
                ans = max(ans, 1 + r[i + 1]);
            }
            if (i > 0 && i < n - 1 && nums[i - 1] <= nums[i + 1]) {
                ans = max(ans, l[i - 1] + 1 + r[i + 1]);
            }
        }
        
        return ans;
    }
};
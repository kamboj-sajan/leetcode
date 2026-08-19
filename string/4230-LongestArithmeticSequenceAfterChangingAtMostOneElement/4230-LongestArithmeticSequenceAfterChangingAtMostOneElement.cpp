// Last updated: 19/08/2026, 15:17:16
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        vector<int> l(n, 2);
        vector<int> r(n, 2);
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                l[i] = l[i - 1] + 1;
            }
        }
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) {
                r[i] = r[i + 1] + 1;
            }
        }
            int ans = min(n, 3);
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n) ans = max(ans, l[i] + 1);
            if (i - 1 >= 0) ans = max(ans, r[i] + 1);
        }
        for (int i = 1; i < n - 1; ++i) {
            if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {
                int d = (nums[i + 1] - nums[i - 1]) / 2;
                int cur = 1;
                if (i - 1 >= 1 && nums[i - 1] - nums[i - 2] == d) {
                    cur += l[i - 1];
                } else {
                    cur += 1; 
                }

                if (i + 1 < n - 1 && nums[i + 2] - nums[i + 1] == d) {
                    cur += r[i + 1];
                } else {
                    cur += 1; 
                }
                
                ans = max(ans, cur);
            }
        }
        
        return min(ans, n);
    }
};
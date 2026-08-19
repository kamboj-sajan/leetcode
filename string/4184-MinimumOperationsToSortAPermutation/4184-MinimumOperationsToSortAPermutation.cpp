// Last updated: 19/08/2026, 15:18:00
class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
        if (n == 1) return 0;
        
        int pos0 = -1;
        int drops = 0;
        int rises = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) pos0 = i;
            if (nums[i] > nums[(i + 1) % n]) drops++;
            if (nums[i] < nums[(i + 1) % n]) rises++;
        }
        
        int ans = 1e9;
        
        if (drops <= 1) {
            ans = std::min(ans, pos0);
            if (pos0 != 0) ans = std::min(ans, n - pos0 + 2);
        }
        
        if (rises <= 1) {
            ans = std::min(ans, n - pos0);
            ans = std::min(ans, pos0 + 2);
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};
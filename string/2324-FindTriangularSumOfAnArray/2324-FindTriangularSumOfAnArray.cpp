// Last updated: 19/08/2026, 15:32:15
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        // Keep reducing until only one element remains
        for (int len = n; len > 1; --len) {
            for (int i = 0; i < len - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};
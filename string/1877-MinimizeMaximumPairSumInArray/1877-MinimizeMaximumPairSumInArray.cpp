// Last updated: 25/09/2026, 01:09:08
class Solution {
public:
    int minPairSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }

        return ans;
    }
};
// Last updated: 19/08/2026, 16:12:34
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end(),target);
        return it - nums.begin();
    }
};
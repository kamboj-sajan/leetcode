// Last updated: 25/09/2026, 00:53:33
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int a = nums[n-1];
        int b = nums[n-2];
        return (a+b-nums[0]);
    }
};
// Last updated: 25/09/2026, 00:58:15
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size(); ++i){
            ans += nums[i];
        }
        return ans%k;
    }
};
// Last updated: 19/08/2026, 15:21:46
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)return n;
        int maxi = 2;
        int curr = 2;
        for(int i=2; i<n; ++i){
            if(nums[i] == nums[i-1] + nums[i-2]){
                curr++;
            }else{
                curr = 2;
            }
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};
// Last updated: 19/08/2026, 15:19:38
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); ++i){
            maxi = max(maxi,nums[i]);
        }
        int ans = 0;
        for(int i=0; i<nums.size(); ++i){
            ans += (maxi - nums[i]);
        }
        return ans;
    }
};
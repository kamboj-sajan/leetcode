// Last updated: 19/08/2026, 15:20:05
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int maxi = 16384;
        vector<int> dp(maxi,-1);
        dp[0] = 0;
        for(int el : nums){
            vector<int> vec = dp;
            for(int i=0; i<maxi; ++i){
                if(dp[i] != -1){
                int a = i ^ el;
                if(dp[i] + 1> vec[a]){
                    vec[a] = dp[i] + 1;
                }
            }
            }
            dp = vec;
        }
        if(dp[target] == -1)return -1;
        return nums.size()- dp[target];
    }
};
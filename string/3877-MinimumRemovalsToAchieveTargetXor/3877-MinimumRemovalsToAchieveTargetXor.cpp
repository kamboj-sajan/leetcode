// Last updated: 25/09/2026, 00:53:47
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